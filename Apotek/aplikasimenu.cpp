#include "aplikasimenu.h"

/*
NAMA : TASYA NURFAUZIAH
NIM : 1301180130
*/

void introduction ()
{
    system("CLS");
    cout<<" TUGAS BESAR STRUKTUR DATA "<<endl;
    cout<<"  'DATA OBAT DI APOTEK'    "<<endl;
    cout<<" ========================= "<<endl;
    cout<<" === GHINA KHOERUNNISA === "<<endl;
    cout<<" === TASYA NUR FAUZIAH === "<<endl<<endl;
    cout<<"ENTER to continue..."<<endl;
    getch();


}
void menu(listPenyakit &LP, listObat &LO, listRelasi &LR)
{
    int choice;


    system("CLS");
    cout<<" MENU APLIKASI "<<endl;
    cout<<" 1. Masukkan Data Penyakit"<<endl;
    cout<<" 2. Masukkan Data Obat"<<endl;
    cout<<" 3. Membuat Relasi Penyakit - Obat"<<endl;
    cout<<" 4. Lihat Data Penyakit"<<endl;
    cout<<" 5. Lihat Data Obat"<<endl;
    cout<<" 6. Lihat Data Semua Relasi"<<endl;
    cout<<" 7. Search Penyakit"<<endl;
    cout<<" 8. Edit Data Penyakit"<<endl;
    cout<<" 9. Edit Data Obat"<<endl;
    cout<<"10. Delete Data Penyakit"<<endl;
    cout<<"11. Delete Data Obat"<<endl;
    cout<<"12. Delete Relasi Penyakit - Obat"<<endl;
    cout<<" 0. KEMBALI KE HALAMAN AWAL"<<endl;
    cout<<"Masukkan Pilihan : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        menuInsertPenyakit(LP);
        menu(LP,LO,LR);
    case 2:
        menuInsertObat(LO);
        menu(LP,LO,LR);
    case 3:
        menuInsertRelasi(LR,LP,LO);
        menu(LP,LO,LR);
    case 4:
        menuviewPenyakit(LP);
        menu(LP,LO,LR);
    case 5:
        menuviewObat(LO);
        menu(LP,LO,LR);
    case 6:
        menuviewRelasi(LR);
        menu(LP,LO,LR);
    case 7:
        menuviewSearchPenyakit(LP);
        menu(LP,LO,LR);
    case 8:
        menuEditPenyakit(LP);
        menu(LP,LO,LR);
    case 9:
        menuEditObat(LO);
        menu(LP,LO,LR);
    case 10:
        menuDeletePenyakit(LP);
        menu(LP,LO,LR);
    case 11:
        menuDeleteObat(LO);
        menu(LP,LO,LR);
    case 12:
        menuDeleteRelasi(LR,LP,LO);
        menu(LP,LO,LR);
    case 0:
        introduction();
    }

}

void menuInsertPenyakit (listPenyakit &LP)
{
    infotypePenyakit P;

    system("CLS");
    cout<<"Masukkan ID : ";
    cin>>P.IDPenyakit;

    bool cek = DuplikatPenyakit(LP,P);
    if (cek != true){
        cout<<"Masukkan Nama Penyakit : ";
        cin>>P.namaPenyakit;
        cout<<"Masukkan Deskripsi Penyakit : ";
        cin>>P.descPenyakit;

        insertfirstPenyakit(LP,alokasiPenyakit(P));
    }
    else
    {
        cout<<"ID Duplikat"<<endl;
    }
    getch();

}
void menuInsertObat (listObat &LO)
{
    infotypeObat O;

    system("CLS");
    cout<<"Masukkan ID Obat : ";
    cin>>O.kodeObat;
    bool cek = cekDuplikatObatbyID(LO,O);
    if (cek != true){

        cout<<"Masukkan Merk Obat : ";
        cin>>O.merkObat;
        cout<<"Masukkan Deskripsi Obat : ";
        cin>>O.descObat;
        cout<<"Masukkan Tipe Obat : ";
        cin>>O.tipeObat;

        insertfirstObat(LO,alokasiObat(O));
    }
    else
    {
        cout<<"ID Duplikat"<<endl;
    }
    getch();
}
void menuInsertRelasi (listRelasi &LR, listPenyakit &LP, listObat &LO)
{
    system("CLS");
    infotypePenyakit X;
    infotypeObat Y;
    addressPenyakit P;
    addressObat O;
    addressRelasi R;

    cout<<"Masukkan Nama Penyakit : ";
    cin>>X.namaPenyakit;
    cout<<"Masukkan ID Obat : ";
    cin>>Y.kodeObat;

    P = searchPenyakitbyNama(LP,X.namaPenyakit);
    O = searchObatbyID(LO,Y.kodeObat);

    if (P != NULL && O != NULL)
    {
        if (!cekDuplikat(LR,P,O))
        {
            R = createNewElmt(P,O);
            insertfirstRelasi(LR,R);
        }
        else
        {
            cout<<"Relasi Penyakit-Obat sudah ada";
        }
    }
    else
    {
        cout<<"Penyakit/Obat tidak ditemukan";
    }
}
void menuviewPenyakit (listPenyakit LP)
{
    system("CLS");
    cout<<"           LIST PENYAKIT         "<<endl;
    viewListPenyakit(LP);
    cout<<endl;
    getch();
    system("CLS");
}
void menuviewObat(listObat LO)
{
    system("CLS");
    cout<<"           LIST OBAT         "<<endl;
    viewListObat(LO);
    cout<<endl;
    getch();
    system("CLS");
}
void menuviewRelasi(listRelasi LR)
{
    system("CLS");
    cout<<"           LIST RELASI PENYAKIT - OBAT          "<<endl;
    viewListRelasi(LR);
    cout<<endl;
    getch();
    system("CLS");
}
void menuDeletePenyakit (listPenyakit &LP)
{
    deletePenyakit(LP);
    cout<<"Delete Sukses";
    getch();
}
void menuDeleteObat (listObat &LO)
{
    delObat(LO);
    cout<<"Delete Sukses";
    getch();
}
void menuDeleteRelasi(listRelasi &LR, listPenyakit LP, listObat LO)
{
    deleteRelasi(LR,LP,LO);
    cout<<"Delete Sukses";
    getch();
}
void menuEditPenyakit (listPenyakit &LP)
{
    system("CLS");
    infotypePenyakit X;
    string cari;
    cout<<"ID tidak dapat diedit"<<endl;
    cout<<"Masukkan Nama Penyakit : ";
    cin>>cari;
    addressPenyakit P = searchPenyakitbyNama(LP,cari);
    editPenyakit(LP,P,X);
    getch();
}
void menuEditObat (listObat &LO)
{
    system("CLS");
    infotypeObat Y;
    string cari;
    cout<<"ID tidak dapat diedit"<<endl;
    cout<<"Masukkan ID Obat : ";
    cin>>cari;
    addressObat O = searchObatbyID(LO,cari);
    editObat(LO,O,Y);
    getch();
}
void menuviewSearchPenyakit (listPenyakit LP)
{
    system("CLS");
    addressPenyakit P;
    string cari;

    cout<<"Masukkan Nama Penyakit : ";
    cin>>cari;

    P = searchPenyakitbyNama(LP, cari);
    if (P!=NULL)
    {
        viewPenyakit(LP,P);
    }
    else
    {
        cout<<"Penyakit tidak ditemukan";
    }
    getch();
}
