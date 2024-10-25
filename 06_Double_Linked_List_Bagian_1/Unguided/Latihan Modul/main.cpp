#include "doublelist.h"
#include "doublelist.cpp"

int main() {
    List L;
    CreateList(L);
    Kendaraan kendaraan;
    string nopol;

    for (int i = 0; i < 4; ++i) {
        cout << "Masukkan nomor polisi: ";
        cin >> kendaraan.nopol;

        if (findElm(L, kendaraan.nopol) != nullptr) {
            cout << "Nomor polisi sudah terdaftar\n" << endl;
            i--; 
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        cin >> kendaraan.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> kendaraan.thnBuat;

        ElmList *P = alokasi(kendaraan);
        insertLast(L, P);
    }

    cout << "\nDATA LIST:\n";
    printInfo(L);

    cout << "Masukkan nomor polisi yang ingin dicari: ";
    cin >> nopol;
    ElmList *found = findElm(L, nopol);
    if (found != nullptr) {
        cout << "Data kendaraan dengan nomor polisi " << nopol << ":\n";
        cout << "Nomor Polisi: " << found->info.nopol << endl;
        cout << "Warna: " << found->info.warna << endl;
        cout << "Tahun Buat: " << found->info.thnBuat << endl;
    } else {
        cout << "Kendaraan dengan nomor polisi " << nopol << " tidak ditemukan.\n";
    }

    cout << "Masukkan nomor polisi yang ingin dihapus: ";
    cin >> nopol;
    ElmList *toDelete = findElm(L, nopol);
    if (toDelete != nullptr) {
        if (toDelete == L.first) {
            deleteFirst(L);
        } else if (toDelete == L.last) {
            deleteLast(L);
        } else {
            deleteAfter(toDelete->prev);
        }
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    } else {
        cout << "Kendaraan dengan nomor polisi " << nopol << " tidak ditemukan untuk dihapus.\n";
    }

    cout << "\nDATA LIST setelah penghapusan:\n";
    printInfo(L);

    return 0;
}
