#include <iostream>
using namespace std;

struct Elemen
{
    int data;
    Elemen *next;
};

struct List
{
    Elemen *first;
};

void createList(List &L)
{
    L.first = NULL;
}


Elemen *alokasi(int x)
{
    Elemen *p = new Elemen;
    if (p != NULL)
    {
        p->data = x;
        p->next = NULL;
    }
    return p;
}

void insertFirst(List &L, Elemen *P)
{
    P->next = L.first;
    L.first = P;
}

void printInfo(List L)
{
    Elemen *p = L.first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


Elemen *findElm(List L, int x)
{
    Elemen *p = L.first;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}


int hitungTotal(List L)
{
    Elemen *p = L.first;
    int total = 0;
    while (p != NULL)
    {
        total += p->data;
        p = p->next;
    }
    return total;
}
