#ifndef PENYAKIT_H_INCLUDED
#define PENYAKIT_H_INCLUDED

#define infoPenyakit(P) (P)->infoPenyakit
#define nextPenyakit(P) (P)->nextPenyakit
#define prevPenyakit(P) (P)->prevPenyakit
#define firstPenyakit(LP) ((LP).firstPenyakit)
#define lastPenyakit(LP) ((LP).lastPenyakit)

#include <iostream>
using namespace std;
/*
NAMA : GHINA KHOERUNNISA
NIM : 1301181066
*/
struct dataPenyakit
{
    string IDPenyakit;
    string namaPenyakit;
    string descPenyakit;
};

typedef struct elmListPenyakit *addressPenyakit;
typedef dataPenyakit infotypePenyakit;

struct elmListPenyakit
{
    infotypePenyakit infoPenyakit;
    addressPenyakit nextPenyakit;
    addressPenyakit prevPenyakit;
};

struct listPenyakit
{
    addressPenyakit firstPenyakit;
    addressPenyakit lastPenyakit;
};

bool isEmptyPenyakit(listPenyakit LP);
void createListPenyakit(listPenyakit &LP);
addressPenyakit alokasiPenyakit(infotypePenyakit X);
void insertfirstPenyakit(listPenyakit &LP, addressPenyakit P);
void insertlastPenyakit(listPenyakit &LP, addressPenyakit P);
void insertafterPenyakit(listPenyakit &LP, addressPenyakit Prec, addressPenyakit P);
void deletefirstPenyakit(listPenyakit &LP, addressPenyakit &P);
void deletelastPenyakit(listPenyakit &LP, addressPenyakit &P);
void deleteafterPenyakit(listPenyakit &LP, addressPenyakit Prec,addressPenyakit &P);
void deletePenyakit(listPenyakit &LP);
addressPenyakit searchPenyakitbyNama(listPenyakit &LP, string dicari);
addressPenyakit searchPenyakitbyID(listPenyakit &LP, string idcari);
bool DuplikatPenyakit(listPenyakit LP, infotypePenyakit X);
void viewListPenyakit(listPenyakit LP);
void viewPenyakit(listPenyakit LP, addressPenyakit P);
void editPenyakit(listPenyakit &LP, addressPenyakit P, infotypePenyakit X);

#endif // PENYAKIT_H_INCLUDED
