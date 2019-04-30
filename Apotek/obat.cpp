#include "obat.h"

/*
NAMA : GHINA KHOERUNNISA
NIM : 1301181066
*/

void createListObat(listObat &LO)
{
    firstObat(LO)= NULL;
    lastObat(LO) = NULL;
}
addressObat alokasiObat(infotypeObat X)
{
    addressObat O = new elmListObat;
    infoObat(O) = X;
    nextObat(O) = NULL;
    prevObat(O) = NULL;
    return O;
}
void insertlastObat(listObat &LO, addressObat O)
{
    if (firstObat(LO)==NULL)
    {
        firstObat(LO) = O;
        lastObat(LO) = O;
    }
    else
    {
        nextObat(lastObat(LO)) = O;
        prevObat(O) = lastObat(LO);
        lastObat(LO) = O;
    }
}
void insertfirstObat(listObat &LO, addressObat O)
{
    if (firstObat(LO) != NULL) {
        nextObat(O) = firstObat(LO);
        prevObat(firstObat(LO)) = O;
        firstObat(LO) = O;
    } else {
        firstObat(LO) = O;
        lastObat(LO) = O;
    }
}
void insertafterObat(listObat &LO, addressObat Prec, addressObat O)
{
    nextObat(O) = nextObat(Prec);
    prevObat(O) = Prec;
    prevObat(nextObat(Prec)) = O;
    nextObat(Prec) = O;
}
void deletefirstObat(listObat &LO, addressObat &O)
{
    if (firstObat(LO) != NULL)
    {
        O = firstObat(LO);
        firstObat(LO) = nextObat(O);
        nextObat(O) = NULL;
        prevObat(firstObat(LO)) = NULL;
    }
}
void deletelastObat(listObat &LO, addressObat &O)
{
    if (firstObat(LO) != lastObat(LO)) {
        O = lastObat(LO);
        lastObat(LO) = prevObat(O);
        prevObat(O) = NULL;
        nextObat(lastObat(LO)) = NULL;
    } else {
        firstObat(LO) = NULL;
        lastObat(LO) = NULL;
    }
}
void deleteafterObat (listObat &LO, addressObat Prec, addressObat &O)
{
    Prec = prevObat(O);
    nextObat(Prec) = nextObat(O);
    prevObat(nextObat(O)) = Prec;
    prevObat(O) = NULL;
    nextObat(O) = NULL;
}
addressObat searchObatbyID(listObat LO, string idcari)
{
    addressObat O = firstObat(LO);
    while (O!=NULL)
    {
        if (infoObat(O).kodeObat == idcari)
        {
            return O;
        }
        O = nextObat(O);
    }
    return NULL;
}
void delObat(listObat &LO)
{
    addressObat Prec;
    addressObat O;

    string cari;
    cout<<"MASUKKAN ID OBAT : ";
    cin>>cari;
    O = searchObatbyID(LO,cari);
    if (O != NULL)
    {
        if (O == firstObat(LO))
        {
            deletefirstObat(LO,O);
            delete O;
        }
        else if (O == lastObat(LO))
        {
            deletelastObat(LO,O);
            delete O;
        }
        else
        {
            Prec = prevObat(O);
            deleteafterObat(LO,Prec,O);
            delete O;
        }
    }
    else
    {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
    }
}
void viewListObat(listObat LO)
{
    if (firstObat(LO) != NULL)
    {
        addressObat O = firstObat(LO);
        while (O!=NULL)
        {
            cout<<"============================================"<<endl;
            cout<<"Kode Obat : "<<infoObat(O).kodeObat<<endl;
            cout<<"Merk Obat : "<<infoObat(O).merkObat<<endl;
            cout<<"Deskripsi : "<<infoObat(O).descObat<<endl;
            cout<<"Tipe Obat : "<<infoObat(O).tipeObat<<endl;
            O = nextObat(O);
        }
    }
    else
    {
        cout<<"LIST OBAT KOSONG"<<endl;
    }
}
bool cekDuplikatObatbyID(listObat LO, infotypeObat Y)
{
    addressObat cek = searchObatbyID(LO, Y.kodeObat);
    if (cek != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void viewObat(listObat LO, addressObat O)
{
    cout<<"   ============================================"<<endl;
    cout<<"   Kode Obat : "<<infoObat(O).kodeObat<<endl;
    cout<<"   Merk Obat : "<<infoObat(O).merkObat<<endl;
    cout<<"   Deskripsi : "<<infoObat(O).descObat<<endl;
    cout<<"   Tipe Obat : "<<infoObat(O).tipeObat<<endl;
}
void editObat(listObat &LO, addressObat O, infotypeObat Y)
{
    if (O!=NULL)
    {
        cout<<"Masukkan Merk Obat (Baru) : ";
        cin>>Y.merkObat;
        cout<<"Masukkan Deskripsi Obat (Baru) : ";
        cin>>Y.descObat;
        cout<<"Masukkan Tipe Obat (Baru) : ";
        cin>>Y.tipeObat;

        infoObat(O).merkObat = Y.merkObat;
        infoObat(O).tipeObat = Y.tipeObat;
        infoObat(O).descObat = Y.descObat;
        cout<<"Data sudah diperbarui"<<endl;
    }
    else
    {
        cout<<"Data tidak ditemukan";
    }
}
