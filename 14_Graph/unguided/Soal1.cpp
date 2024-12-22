#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int jumlahSimpul;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> simpul(jumlahSimpul);
    cout << "Silakan masukkan nama simpul\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Silakan masukkan bobot antar simpul (0 jika tidak ada jalur)\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << simpul[i] << " ==> " << simpul[j] << ": ";
            cin >> bobot[i][j];
        }
    }
    cout << "\nMatriks Bobot:\n";
    cout << setw(8) << " ";
    for (const auto& nama : simpul) {
        cout << setw(8) << nama;
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(8) << simpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(8) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}
