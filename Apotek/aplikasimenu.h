#ifndef APLIKASIMENU_H_INCLUDED
#define APLIKASIMENU_H_INCLUDED

#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <string>

#include "penyakit.h"
#include "obat.h"
#include "relasi.h"

/*
NAMA : TASYA NURFAUZIAH
NIM : 1301180130
*/

void introduction ();
void menu(listPenyakit &LP, listObat &LO, listRelasi &LR);
void menuInsertPenyakit (listPenyakit &LP);
void menuInsertObat (listObat &LO);
void menuInsertRelasi (listRelasi &LR,listPenyakit &LP,listObat &LO);
void menuviewPenyakit (listPenyakit LP);
void menuviewObat (listObat LO);
void menuviewRelasi (listRelasi LR);
void menuDeletePenyakit (listPenyakit &LP);
void menuDeleteObat (listObat &LO);
void menuDeleteRelasi (listRelasi &LR, listPenyakit LP, listObat LO);
void menuEditPenyakit (listPenyakit &LP); //ID tidak dapat diedit//
void menuEditObat (listObat &LO); //ID tidak dapat diedit//
void menuviewSearchPenyakit(listPenyakit LP);



#endif // APLIKASIMENU_H_INCLUDED
