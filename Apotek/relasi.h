#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "penyakit.h"
#include "obat.h"

#define next(R) R->next
#define prev(R) R->prev
#define first(LR) LR.first
#define last(LR) LR.last
#define child(R) R->child
#define parent(R) R->parent

/*
NAMA : TASYA NURFAUZIAH
NIM : 1301180130
*/

typedef struct elmlistRelasi *addressRelasi;

struct elmlistRelasi{
    addressRelasi next;
    addressRelasi prev;
    addressObat child;
    addressPenyakit parent;
};

struct listRelasi{
    addressRelasi first;
    addressRelasi last;
};

void CreateListRelasi(listRelasi &LR);
addressRelasi createNewElmt(addressPenyakit P, addressObat O);
void insertfirstRelasi(listRelasi &LR, addressRelasi R);
void inserAfterRelasi(listRelasi &LR, addressRelasi Prec, addressRelasi R);
void insertLastRelasi(listRelasi &LR, addressRelasi R);
void deleteFirstR(listRelasi &LR, addressRelasi &R);
void deleteLastR(listRelasi &LR, addressRelasi &R);
void deleteAfterR(listRelasi &LR, addressRelasi Prec, addressRelasi &R);
void viewListRelasi(listRelasi LR);
addressRelasi searchRelasiByID(listRelasi LR, addressPenyakit P, addressObat O);
void deleteRelasi(listRelasi &LR, listPenyakit LP, listObat LO);
bool cekDuplikat(listRelasi LR, addressPenyakit P, addressObat O);


#endif // RELASI_H_INCLUDED
