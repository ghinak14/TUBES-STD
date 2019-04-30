#include "relasi.h"

/*
NAMA : TASYA NURFAUZIAH
NIM : 1301180130
*/
void CreateListRelasi(listRelasi &LR)
{
    first(LR) = NULL;
    last(LR) = NULL;
}
addressRelasi createNewElmt(addressPenyakit P, addressObat O)
{
    addressRelasi R = new elmlistRelasi;
    parent(R) = P;
    child(R) = O;
    next(R) = NULL;
    prev(R) = NULL;
    return R;
}
void insertfirstRelasi(listRelasi &LR, addressRelasi R)
{
    if (first(LR) != NULL) {
        next(R) = first(LR);
        prev(first(LR)) = R;
        first(LR) = R;
    } else {
        first(LR) = R;
        last(LR) = R;
    }
}
void inserAfterRelasi(listRelasi &LR, addressRelasi Prec, addressRelasi R)
{
    next(R) = next(Prec);
    prev(R) = Prec;
    prev(next(Prec)) = R;
    next(Prec) = R;
}
void insertLastRelasi(listRelasi &LR, addressRelasi R)
{
    if (first(LR)==NULL)
    {
        first(LR) = R;
        last(LR) = R;
    }
    else
    {
        next(last(LR)) = R;
        prev(R) = last(LR);
        last(LR) = R;
    }
}
void deleteFirstR(listRelasi &LR, addressRelasi &R)
{
    if (first(LR) != last(LR))
    {
        R = first(LR);
        first(LR) = next(R);
        next(R) = NULL;
        prev(first(LR)) = NULL;
    }
    else
    {
        first(LR) = NULL;
        last(LR) = NULL;
    }
}
void deleteLastR(listRelasi &LR, addressRelasi &R)
{
    if (first(LR) != last(LR)) {
        R = last(LR);
        last(LR) = prev(R);
        prev(R) = NULL;
        next(last(LR)) = NULL;
    } else {
        first(LR) = NULL;
        last(LR) = NULL;
    }
}
void deleteAfterR(listRelasi &LR, addressRelasi Prec, addressRelasi &R)
{
    Prec = prev(R);
    next(Prec) = next(R);
    prev(next(R)) = Prec;
    prev(R) = NULL;
    next(R) = NULL;
}
void viewListRelasi(listRelasi LR)
{
    addressRelasi R = first(LR);
    listPenyakit LP;
    listObat LO;
    int i = 1;

    if (first(LR) == NULL){
        cout<<"Data Tidak Ada"<<endl;
    }
    else{
        while (R != NULL){
            cout<<i<<". "<<infoPenyakit(parent(R)).namaPenyakit<<" - "<<infoObat(child(R)).merkObat<<endl;
            cout<<"             Detail Penyakit dan Obat"          <<endl;
            cout<<"   |******************************************|"<<endl;
            viewPenyakit(LP,parent(R));
            viewObat(LO,child(R));
            cout<<"   |******************************************|"<<endl;
            i++;
            R = next(R);
        }
    }
}
addressRelasi searchRelasiByID(listRelasi LR, addressPenyakit P, addressObat O)
{
    addressRelasi R = first(LR);
    while (R!=NULL)
    {
        if ((infoPenyakit(parent(R)).IDPenyakit == infoPenyakit(P).IDPenyakit) &&
            (infoObat(child(R)).kodeObat == infoObat(O).kodeObat))
        {
            return R;
        }
        R = next(R);
    }
    return NULL;
}
bool cekDuplikat(listRelasi LR, addressPenyakit P, addressObat O)
{
    addressRelasi R = searchRelasiByID(LR,P,O);
    if (R != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void deleteRelasi(listRelasi &LR, listPenyakit LP, listObat LO)
{
    infotypePenyakit X;
    infotypeObat Y;
    addressObat O;
    addressPenyakit P;
    addressRelasi R;
    cout<<"MASUKKAN NAMA PENYAKIT (DELETE) : ";
    cin>>X.namaPenyakit;
    cout<<"MASUKKAN ID OBAT {DELETE) : ";
    cin>>Y.kodeObat;
    O = searchObatbyID(LO,Y.kodeObat);
    P = searchPenyakitbyNama(LP,X.namaPenyakit);
    if (O != NULL && P != NULL)
    {
        R = searchRelasiByID(LR,P,O);
        if (R != NULL)
        {
            if (R == first(LR))
            {
                deleteFirstR(LR,R);
                delete R;
            }
            else if (R == last(LR))
            {
                deleteLastR(LR,R);
                delete R;
            }
            else
            {
                deleteAfterR(LR,prev(R),R);
                delete R;
            }
        }
        else
        {
            cout<<"Tidak ditemukan relasi"<<endl;
        }
    }
    else{
        cout<<"Penyakit/Obat tidak ditemukan"<<endl;
    }
}
