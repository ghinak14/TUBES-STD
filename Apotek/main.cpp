#include "aplikasimenu.h"
#include <iostream>

using namespace std;

int main()
{
    listPenyakit LP;
    listObat LO;
    listRelasi LR;

    createListPenyakit(LP);
    createListObat(LO);
    CreateListRelasi(LR);

    introduction();

    menu(LP,LO,LR);
    return 0;
}
