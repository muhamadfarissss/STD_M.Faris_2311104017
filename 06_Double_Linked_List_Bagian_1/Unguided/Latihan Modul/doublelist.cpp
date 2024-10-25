#include "doublelist.h"

void CreateList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

ElmList* alokasi(Kendaraan x) {
    ElmList *P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(ElmList *&P) {
    delete P;
    P = nullptr;
}

void printInfo(const List &L) {
    ElmList *temp = L.first;
    while (temp != nullptr) {
        cout << "Nomor Polisi: " << temp->info.nopol << endl;
        cout << "Warna: " << temp->info.warna << endl;
        cout << "Tahun Buat: " << temp->info.thnBuat << endl << endl;
        temp = temp->next;
    }
}

void insertLast(List &L, ElmList *P) {
    if (L.first == nullptr) { 
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

ElmList* findElm(const List &L, const string &nopol) {
    ElmList *temp = L.first;
    while (temp != nullptr) {
        if (temp->info.nopol == nopol) {
            return temp; 
        }
        temp = temp->next;
    }
    return nullptr; 
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        ElmList *P = L.first;
        if (L.first == L.last) { 
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = L.first->next;
            L.first->prev = nullptr;
        }
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.last != nullptr) {
        ElmList *P = L.last;
        if (L.first == L.last) { 
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = L.last->prev;
            L.last->next = nullptr;
        }
        dealokasi(P);
    }
}

void deleteAfter(ElmList *Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        ElmList *P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        } else {
            
        }
        dealokasi(P);
    }
}
