#include <iostream>

using namespace std;

int main(){
    int data[10];

    cout << "Masukan angka: " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> data[i];
    }

    cout << "angka: ";
    for (int i = 0; i < 10; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "genap: ";
    for (int i = 0; i < 10; i++){
        if (data[i] % 2 == 0){
            cout << data [i] << " ";
        }
    }
    cout << endl;

    cout << "ganjil: ";
    for( int i = 0; i < 10; i++){
        if (data[i] % 2 != 0) {
            cout << data[i] << " ";
        }
    }
    cout << endl;
    return 0;
}