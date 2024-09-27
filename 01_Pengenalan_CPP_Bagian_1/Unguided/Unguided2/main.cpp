#include <iostream>
#include <string>
using namespace std;

string angka_tulisan(int angka, string satuan[], string belasan[], string puluhan[]) {
    if (angka == 0) return "nol";
    if (angka == 100) return "seratus";
    if (angka < 10) return satuan[angka];
    if (angka < 20) return belasan[angka - 10];
    return puluhan[angka / 10] + (angka % 10 ? " " + satuan[angka % 10] : "");
}
int main() {
    int angka;
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
                        "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh",
                        "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
    cout << "Masukan angka 0 - 100: ";
    cin >> angka;
    cout << angka_tulisan(angka, satuan, belasan, puluhan) << endl;
    return 0;
}
