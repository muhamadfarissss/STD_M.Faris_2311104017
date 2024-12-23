#include <iostream>
#include "SLL.cpp"

int main()
{
    List L;
    Elemen *P1, *P2, *P3, *P4, *P5 = NULL;
    createList(L);

    // alokasi + insert data
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    Elemen *found = findElm(L, 8);
    if (found != NULL)
    {
        cout << "Elemen dengan nilai 8 ditemukan" << endl;
    }
    else
    {
        cout << "Elemen dengan nilai 8 tidak ditemukan" << endl;
    }
    
    int total = hitungTotal(L);
    cout << "Total elemen keseluruhan: " << total << endl;
}