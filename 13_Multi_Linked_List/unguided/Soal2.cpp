#include <iostream>
#include <string>
using namespace std;
struct Buku {
    string judul_buku;
    string tanggal_pengembalian;
};
typedef Buku infotypeBuku;
typedef struct elemenBuku *addressBuku;

struct elemenBuku{
    infotypeBuku info;
    addressBuku next;
};
struct Anggota{
    string name;
    string id;
};
typedef Anggota infotypeAnggota;
typedef struct elemenAnggota * addressAnggota;

struct elemenAnggota{
    infotypeAnggota info;
    addressBuku firstBuku;
    addressAnggota next;
};
struct ListAnggota{
    addressAnggota first;
};
void createListAnggita(ListAnggota &L){
    L.first = nullptr;
}
addressAnggota allocateAnggota(infotypeAnggota data){
    addressAnggota p = new elemenAnggota;
    p->info = data;
    p->firstBuku = nullptr;
    p->next = nullptr;
    return p;
}
addressBuku allocateBuku(infotypeBuku data){
    addressBuku p = new elemenBuku;
    p->info = data;
    p->next = nullptr;
    return p;
}
void insertlastAnggota(ListAnggota &L, addressAnggota p){
    if(L.first == nullptr){
        L.first = p;
    } else {
        addressAnggota q = L.first;
        while (q->next != nullptr){
            q= q->next;
        }
        q->next = p;
    }
}
void insertBukuToAnggota(addressAnggota anggota, addressBuku buku){
    if(anggota->firstBuku == nullptr){
        anggota->firstBuku = buku;
    } else {
        addressBuku q = anggota->firstBuku;
        while(q->next != nullptr){
            q = q->next;
        }
        q->next = buku;
    }
}
void printListAnggota(const ListAnggota &L){
    addressAnggota p = L.first;
    while(p!= nullptr){
        cout << "Anggota: " << p->info.name << "(ID: " << p->info.id << ")\n";
         addressBuku q = p->firstBuku;
        while (q != nullptr) {
            cout << "  - Buku: " << q->info.judul_buku << " (Pengembalian: " << q->info.tanggal_pengembalian << ")\n";
            q = q->next;
        }
        cout << endl;
        p = p->next;
    }
}

// Mencari anggota berdasarkan ID
addressAnggota findAnggotaByID(const ListAnggota &L, const string &id) {
    addressAnggota p = L.first;
    while (p != nullptr) {
        if (p->info.id == id) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// Menghapus anggota dan semua buku yang dipinjam
void removeAnggota(ListAnggota &L, const string &id) {
    addressAnggota current = L.first;
    addressAnggota prev = nullptr;

    while (current != nullptr && current->info.id != id) {
        prev = current;
        current = current->next;
    }
    if (current != nullptr) {
        if (prev == nullptr) {
            L.first = current->next;
        } else {
            prev->next = current->next;
        }

        // Hapus semua buku yang dipinjam anggota
        addressBuku buku = current->firstBuku;
        while (buku != nullptr) {
            addressBuku temp = buku;
            buku = buku->next;
            delete temp;
        }

        delete current;
        cout << "Anggota dengan ID " << id << " telah dihapus beserta buku yang dipinjam.\n";
    } else {
        cout << "Anggota dengan ID " << id << " tidak ditemukan.\n";
    }
}
int main() {
    ListAnggota L;
    createListAnggita(L);


    infotypeAnggota anggota1 = {"Rani", "A001"};
    infotypeAnggota anggota2 = {"Dito", "A002"};
    infotypeAnggota anggota3 = {"Vina", "A003"};

    addressAnggota p1 = allocateAnggota(anggota1);
    addressAnggota p2 = allocateAnggota(anggota2);
    addressAnggota p3 = allocateAnggota(anggota3);

    insertlastAnggota(L, p1);
    insertlastAnggota(L, p2);
    insertlastAnggota(L, p3);

    // Menambahkan buku yang dipinjam
    infotypeBuku buku1 = {"Pemrograman C++", "01/12/2024"};
    infotypeBuku buku2 = {"Algoritma Pemrograman", "15/12/2024"};
    infotypeBuku buku3 = {"Struktur Data", "10/12/2024"};

    insertBukuToAnggota(p1, allocateBuku(buku1));
    insertBukuToAnggota(p2, allocateBuku(buku2));
    insertBukuToAnggota(p1, allocateBuku(buku3));

    // Menghapus anggota Dito beserta buku yang dipinjam
    removeAnggota(L, "A002");

    // Menampilkan seluruh data anggota dan buku yang dipinjam
    printListAnggota(L);

    return 0;
}

 