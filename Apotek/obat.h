#ifndef OBAT_H_INCLUDED
#define OBAT_H_INCLUDED

#define infoObat(O) (O)->infoObat
#define nextObat(O) (O)->nextObat
#define prevObat(O) (O)->prevObat
#define firstObat(LO) ((LO).firstObat)
#define lastObat(LO) ((LO).lastObat)

#include <iostream>
using namespace std;
/*
NAMA : GHINA KHOERUNNISA
NIM : 1301181066
*/
struct dataObat
{
    string kodeObat;
    string merkObat;
    string descObat;
    string tipeObat;
};

typedef struct elmListObat *addressObat;
typedef dataObat infotypeObat;

struct elmListObat
{
    infotypeObat infoObat;
    addressObat nextObat;
    addressObat prevObat;
};

struct listObat
{
    addressObat firstObat;
    addressObat lastObat;
};

void createListObat(listObat &LO);
addressObat alokasiObat(infotypeObat O);
void insertlastObat(listObat &LO, addressObat O);
void insertfirstObat(listObat &LO, addressObat O);
void insertafterObat(listObat &LO, addressObat Prec, addressObat O);
void deletefirstObat(listObat &LO, addressObat &O);
void deletelastObat(listObat &LO, addressObat &O);
void deleteafterObat (listObat &LO, addressObat Prec, addressObat &O);
void delObat(listObat &LO);
void editObat(listObat &LO, addressObat O, infotypeObat Y);
void viewListObat(listObat LO);
void viewObat(listObat LO, addressObat O);
bool cekDuplikatObatbyID(listObat LO, infotypeObat Y);
addressObat searchObatbyID(listObat LO, string idcari);

#endif // OBAT_H_INCLUDED
