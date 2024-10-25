#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList {
    Kendaraan info;
    ElmList *next;
    ElmList *prev;
};

struct List {
    ElmList *first;
    ElmList *last;
};


void CreateList(List &L);
ElmList* alokasi(Kendaraan x);
void dealokasi(ElmList *&P);
void printInfo(const List &L);
void insertLast(List &L, ElmList *P);
ElmList* findElm(const List &L, const string &nopol);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(ElmList *Prec);

#endif 
