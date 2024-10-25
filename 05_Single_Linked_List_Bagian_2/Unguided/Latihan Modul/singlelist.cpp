#include "singlelist.h"
void createList(List &L) {
    L.First = nullptr;
}
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void printInfo(const List &L) {
    address P = L.First;
    while (P != nullptr) {
        cout << P->info;
        if (P->next != nullptr) cout << "->";
        P = P->next;
    }
    cout << endl;
}


void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

bool findElm(const List &L, infotype x) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info == x) {
            return true; 
        }
        P = P->next;
    }
    return false; 
}
int totalInfo(const List &L) {
    int sum = 0;
    address P = L.First;
    while (P != nullptr) {
        sum += P->info;
        P = P->next;
    }
    return sum;
}
int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

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

    cout << "Isi list: ";
    printInfo(L);

    if (findElm(L, 8)) {
        cout << "Elemen dengan info 8 ditemukan dalam list." << endl;
    } else {
        cout << "Elemen dengan info 8 tidak ditemukan dalam list." << endl;
    }
    int total = totalInfo(L);
    cout << "Jumlah total info seluruh elemen: " << total << endl;

    return 0;
}
