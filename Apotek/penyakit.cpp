#include "penyakit.h"

/*
NAMA : GHINA KHOERUNNISA
NIM : 1301181066
*/

bool isEmptyPenyakit(listPenyakit LP)
{
    return (firstPenyakit(LP)==NULL);
}
void createListPenyakit(listPenyakit &LP)
{
    firstPenyakit(LP) = NULL;
    lastPenyakit(LP) = NULL;
}
addressPenyakit alokasiPenyakit(infotypePenyakit X)
{
    addressPenyakit P = new elmListPenyakit;
    infoPenyakit(P).IDPenyakit = X.IDPenyakit;
    infoPenyakit(P).namaPenyakit = X.namaPenyakit;
    infoPenyakit(P).descPenyakit = X.descPenyakit;
    nextPenyakit(P) = NULL;
    prevPenyakit(P) = NULL;
    return P;
}
void insertlastPenyakit(listPenyakit &LP, addressPenyakit P)
{
    if (isEmptyPenyakit(LP))
    {
        firstPenyakit(LP) = P;
        lastPenyakit(LP) = P;
    }
    else
    {
        nextPenyakit(lastPenyakit(LP)) = P;
        prevPenyakit(P) = lastPenyakit(LP);
        lastPenyakit(LP) = P;
    }
}
void insertfirstPenyakit(listPenyakit &LP, addressPenyakit P)
{
    if (isEmptyPenyakit(LP))
    {
        firstPenyakit(LP) = P;
        lastPenyakit(LP) = P;
    }
    else
    {
        nextPenyakit(P) = firstPenyakit(LP);
        prevPenyakit(firstPenyakit(LP)) = P;
        firstPenyakit(LP) = P;
    }
}
void insertafterPenyakit(listPenyakit &LP, addressPenyakit Prec, addressPenyakit P)
{
    nextPenyakit(P) = nextPenyakit(Prec);
    prevPenyakit(P) = Prec;
    prevPenyakit(nextPenyakit(Prec)) = P;
    nextPenyakit(Prec) = P;
}
void deletefirstPenyakit(listPenyakit &LP, addressPenyakit &P)
{
    if (!isEmptyPenyakit(LP))
    {
        P = firstPenyakit(LP);
        firstPenyakit(LP) = nextPenyakit(P);
        nextPenyakit(P) = NULL;
        prevPenyakit(firstPenyakit(LP)) = NULL;
    }
    else
    {
        P = firstPenyakit(LP);
        firstPenyakit(LP) = NULL;
        lastPenyakit(LP) = NULL;
    }
}
void deletelastPenyakit(listPenyakit &LP, addressPenyakit &P)
{
    if (firstPenyakit(LP) != lastPenyakit(LP)) {
        P = lastPenyakit(LP);
        lastPenyakit(LP) = prevPenyakit(P);
        prevPenyakit(P) = NULL;
        nextPenyakit(lastPenyakit(LP)) = NULL;
    } else {
        firstPenyakit(LP) = NULL;
        lastPenyakit(LP) = NULL;
    }
}
void deleteafterPenyakit(listPenyakit &LP, addressPenyakit Prec,addressPenyakit &P)
{
    Prec = prevPenyakit(P);
    nextPenyakit(Prec) = nextPenyakit(P);
    prevPenyakit(nextPenyakit(P)) = Prec;
    prevPenyakit(P) = NULL;
    nextPenyakit(P) = NULL;
}
addressPenyakit searchPenyakitbyNama(listPenyakit &LP, string dicari)
{
    addressPenyakit P = firstPenyakit(LP);
    while (P!=NULL)
    {
        if (infoPenyakit(P).namaPenyakit == dicari)
        {
            return P;
        }
        P = nextPenyakit(P);
    }
    return NULL;
}
addressPenyakit searchPenyakitbyID(listPenyakit &LP, string idcari)
{
    addressPenyakit P = firstPenyakit(LP);
    while (P!=NULL)
    {
        if (infoPenyakit(P).IDPenyakit == idcari)
        {
            return P;
        }
        P = nextPenyakit(P);
    }
    return NULL;
}
void deletePenyakit(listPenyakit &LP)
{
    addressPenyakit P;
    string cari;
    cout<<"NAMA PENYAKIT YANG DIDELETE : ";
    cin>>cari;
    P = searchPenyakitbyNama(LP,cari);
    if (P != NULL)
    {
        if (P == firstPenyakit(LP))
        {
            deletefirstPenyakit(LP,P);
            delete P;
        }
        else if (P == lastPenyakit(LP))
        {
            deletelastPenyakit(LP,P);
            delete P;
        }
        else
        {
            deleteafterPenyakit(LP,prevPenyakit(P),P);
            delete P;
        }
    }
    else
    {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
    }
}
bool DuplikatPenyakit(listPenyakit LP, infotypePenyakit X)
{
    addressPenyakit cek = searchPenyakitbyID(LP,X.IDPenyakit);
    if (cek != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void viewListPenyakit(listPenyakit LP)
{
    if (!isEmptyPenyakit(LP))
    {
        addressPenyakit P = firstPenyakit(LP);
        while (P!=NULL)
        {
            cout<<"============================================"<<endl;
            cout<<"ID Penyakit : "<<infoPenyakit(P).IDPenyakit<<endl;
            cout<<"Nama Penyakit : "<<infoPenyakit(P).namaPenyakit<<endl;
            cout<<"Deskripsi : "<<infoPenyakit(P).descPenyakit<<endl;
            P = nextPenyakit(P);
        }
    }
    else
    {
        cout<<"LIST PENYAKIT KOSONG"<<endl;
    }
}
void editPenyakit(listPenyakit &LP, addressPenyakit P, infotypePenyakit X)
{
    if (P!=NULL)
    {
        cout<<"Masukkan Nama Penyakit (Baru) : ";
        cin>>X.namaPenyakit;
        cout<<"Masukkan Deskripsi Penyakit (Baru) : ";
        cin>>X.descPenyakit;

        infoPenyakit(P).namaPenyakit = X.namaPenyakit;
        infoPenyakit(P).descPenyakit = X.descPenyakit;
        cout<<"Data sudah diperbarui"<<endl;
    }
    else
    {
        cout<<"Data tidak ditemukan";
    }
}
void viewPenyakit(listPenyakit LP, addressPenyakit P)
{
    cout<<"   ============================================"<<endl;
    cout<<"   ID Penyakit : "<<infoPenyakit(P).IDPenyakit<<endl;
    cout<<"   Nama Penyakit : "<<infoPenyakit(P).namaPenyakit<<endl;
    cout<<"   Deskripsi : "<<infoPenyakit(P).descPenyakit<<endl;
}
