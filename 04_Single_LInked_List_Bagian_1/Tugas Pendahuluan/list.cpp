#include <iostream>
#include "list.h"
using namespace std;

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x) {
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}
void insertAfter(List &L, address P, address Prec) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void deleteLast(List &L, address &P) {
    if (first(L) == NULL) {
        P = NULL;
    } else if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
    } else {
        address prev = NULL;
        address last = first(L);
        while (next(last) != NULL) {
            prev = last;
            last = next(last);
        }
        P = last;
        next(prev) = NULL;
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != NULL) {
        P = next(Prec);
        if (P != NULL) {
            next(Prec) = next(P);
        }
    }
}

address searchInfo(List L, infotype x) {
    address p = first(L);
    while (p != NULL) {
        if (info(p) == x) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

void printInfo(List L) {
    address p = first(L);
    while (p != NULL) {
        cout << info(p) << " ";
        p = next(p);
    }
    cout << endl;
}

int main() {
    List L;
    int angka;
    address p;
    createList(L);

    cout << "Masukkan NIM per digit:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << "Digit " << i << " : ";
        cin >> angka;
        p = allocate(angka);
        insertLast(L, p);  
    }
    cout << "Isi list: ";
    printInfo(L);
    return 0;
}
