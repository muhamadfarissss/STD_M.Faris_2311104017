#include <iostream>
#include <string>
using namespace std;

//strutur mahasiswa
struct Mahasiswa{
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef Mahasiswa infotype;
typedef struct Elmlist *address;

struct Elmlist{
    infotype info;
    address next; //pointer ke elemen berikutnya
};
struct list{
    address first;//menyimpan pointer ke elemen head
};
//membuat list kosong dengan pointer first
void createList(list &L){
    L.first = nullptr;
}
// membuat elemen (node) baru pda list
address allocate(infotype data){
    address p = new Elmlist;
    p->info = data;
    p->next = nullptr;
    return p;
}
// menambahkan elemen di awal
void insertFirst(list &L, address p){
    if(L.first == nullptr){
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}
// menambahkan elemen di akhir
void insertLast(list &L, address p){
    if(L.first == nullptr){
        L.first = p;
    } else {
        address Q = L.first;
        while (Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = p;
    }
}
// menambahkan elemen setelah elemen tertentu
void insertAfter(address prec, address p){
    if(prec != nullptr){
        p->next = prec->next;
        prec->next = p;
    }
}

void printList(const list &L){
    address p = L.first;
    while(p != nullptr){
        cout << "nama: " << p->info.nama << endl;
        cout << "nim: " << p->info.nim << endl;
        cout << "L/P: " << p->info.jenis_kelamin << endl;
        cout << "IPK: " << p->info.ipk << endl;
        cout << endl;
        p = p->next;
    }
}
int main(){
    list L;
    createList(L);

    infotype m1 = {"Ali", "01", 'L', 3.3};
    infotype m2 = {"ppp", "02", 'L', 3.4};
    infotype m3 = {"lll", "03", 'L', 3.5};
    infotype m4 = {"ooo", "04", 'L', 3.3};
    infotype m5 = {"kkk", "05", 'L', 3.7};
    infotype m6 = {"sss", "06", 'L', 3.1};
    infotype m7 = {"qqq", "07", 'L', 3.8};
    infotype m8 = {"vvv", "08", 'L', 3.9};
    
    //alokasi elemen
    address p1 = allocate(m1);
    address p2 = allocate(m2);
    address p3 = allocate(m3);
    address p4 = allocate(m4);
    address p5 = allocate(m5);
    address p6 = allocate(m6);
    address p7 = allocate(m7);
    address p8 = allocate(m8);

    //Memasaukan elemen ke list
    insertFirst(L, p1);
    insertLast(L, p2);
    insertLast(L, p4);
    insertAfter(p2,p3);
    insertLast(L, p5);
    insertLast(L, p6);
    insertLast(L, p7);
    insertLast(L, p8);

    cout << "coba insert first, last dan after\n" << endl;
    printList(L);
    return 0;

}