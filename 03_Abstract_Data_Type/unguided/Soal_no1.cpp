#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas){
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main(){
    Mahasiswa mahasiswa[10];
    int jumlah;

    cout << "Masukan jumlah mahasiswa maksimal 10 :";
    cin >> jumlah;

    if (jumlah > 10) {
        cout << "Jumlah mahasiswa tidak boleh lebih dari 10" << endl;
        return 1;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nNama: ";cin >> ws; getline(cin, mahasiswa[i].nama);
        cout << "NIM: "; cin >> mahasiswa[i].nim;
        cout << "UTS: "; cin >> mahasiswa[i].uts;
        cout << "UAS: "; cin >> mahasiswa[i].uas;
        cout << "tugas: "; cin >> mahasiswa[i].tugas;

        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }

    cout << "\nData Mahasiswa : \n";
    for (int i = 0; i < jumlah; i++){
        cout << "Nama: " << mahasiswa[i].nama <<endl;
        cout << "Nim: " << mahasiswa[i].nim <<endl;
        cout << "Nilaiakhir: " << mahasiswa[i].nilaiAkhir <<endl;
    
    }
}