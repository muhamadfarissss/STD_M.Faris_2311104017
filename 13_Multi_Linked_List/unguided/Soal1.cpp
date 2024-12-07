#include <iostream>
#include <string>
using namespace std;

struct Proyek {
    string nama_proyek;
    int durasi;
};
typedef Proyek infotypeProyek;
typedef struct ElemenProyek *addressProyek;

struct ElemenProyek{
    infotypeProyek info;
    addressProyek next;
};
struct pegawai {
    string nama;
    string id;
};
typedef pegawai infotypePegawai;
typedef struct ElemenPegawai *addressPegawai;

struct ElemenPegawai{
    infotypePegawai info;
    addressProyek firstProyek;
    addressPegawai next;
};
struct ListPegawai{
    addressPegawai first;
};
void createListPegawai(ListPegawai &L){
    L.first = nullptr;
}
addressPegawai allocatePegawai(infotypePegawai data){
    addressPegawai p = new ElemenPegawai;
    p->info = data;
    p->firstProyek = nullptr;
    p->next = nullptr;
    return p;
}
addressProyek allocateProyek(infotypeProyek data){
    addressProyek p = new ElemenProyek;
    p->info = data;
    p->next = nullptr;
    return p;
}
void insertlastPegawai(ListPegawai &L, addressPegawai p){
    if(L.first == nullptr){
        L.first = p;
    } else {
        addressPegawai q = L.first;
        while (q->next != nullptr){
            q = q->next;
        }
        q->next = p;
    }
}
void insertProyekToPegawai(addressPegawai pegawai, addressProyek proyek){
    if(pegawai -> firstProyek == nullptr){
        pegawai->firstProyek = proyek;
    } else {
        addressProyek q = pegawai->firstProyek;
        while (q->next != nullptr){
            q = q->next;
        }
        q->next = proyek;
    }
}
void printListPegawai(const ListPegawai &L){
    addressPegawai p = L.first;
    while(p != nullptr){
        cout << "Pegawai: " << p->info.nama << "(ID: " << p->info.id << ")\n";
        addressProyek q = p->firstProyek;
        while (q != nullptr){
            cout << " - Proyek: " << q->info.nama_proyek << "(Durasi: " << q->info.durasi << " bulan)\n";
            q = q->next;
        }
        cout << endl;
        p = p->next;
    }
}
addressPegawai findPegawaiByID(const ListPegawai &L, const string &id){
    addressPegawai p = L.first;
    while (p != nullptr){
        if(p->info.id == id){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
void removeProyekFromPegawai(addressPegawai pegawai, const string &namaProyek){
    addressProyek current = pegawai->firstProyek;
    addressProyek prev = nullptr;

    while(current != nullptr && current->info.nama_proyek != namaProyek){
        prev = current;
        current = current->next;
    }
    if(current != nullptr){
        if(prev == nullptr){
            pegawai->firstProyek = current->next;
        } else {
            prev->next = current ->next;
        }
        delete current;
        cout << "Proyek " << namaProyek << " telah dihapus dari pegawai " << pegawai->info.nama << ".\n";
    } else {
        cout << "Proyek" << namaProyek << "tidak ditemukan dari pegawai" << pegawai->info.nama << ".\n";
    }
}
int main(){
    ListPegawai L;
    createListPegawai(L);

    infotypePegawai pegawai1 = {"Andi", "P001"};
    infotypePegawai pegawai2 = {"Budi", "P002"};
    infotypePegawai pegawai3 = {"Citra", "P003"};

    addressPegawai p1 = allocatePegawai(pegawai1);
    addressPegawai p2 = allocatePegawai(pegawai2);
    addressPegawai p3 = allocatePegawai(pegawai3);

    insertlastPegawai(L, p1);
    insertlastPegawai(L, p2);
    insertlastPegawai(L, p3);

    // Menambahkan proyek ke pegawai
    infotypeProyek proyek1 = {"Aplikasi Mobile", 12};
    infotypeProyek proyek2 = {"Sistem Akuntansi", 8};
    infotypeProyek proyek3 = {"E-commerce", 10};
    infotypeProyek proyek4 = {"Analisis Data", 6};

    insertProyekToPegawai(p1, allocateProyek(proyek1));
    insertProyekToPegawai(p2, allocateProyek(proyek2));
    insertProyekToPegawai(p3, allocateProyek(proyek3));
    insertProyekToPegawai(p1, allocateProyek(proyek4));

    // Menghapus proyek "Aplikasi Mobile" dari Andi
    removeProyekFromPegawai(p1, "Aplikasi Mobile");

    // Menampilkan data pegawai dan proyek mereka
    printListPegawai(L);

    return 0;
}