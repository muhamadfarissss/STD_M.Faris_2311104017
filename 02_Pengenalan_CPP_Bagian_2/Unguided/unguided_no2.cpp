#include <iostream>
using namespace std;

int main (){
    int x, y, z;

    cout << "Masukan ukuran 1: ";
    cin >> x;
    cout << "Masukan ukuran 2: ";
    cin >> y;
    cout << "Masukan ukuran 3: ";
    cin >> z;

    int array [x][y][z];

    cout << "Masukan elemen : " << endl;
    for (int i =0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++){
                cout << "elemen [" << i << "][" << j << "][" << k <<"]: ";
                cin >> array[i][j][k];
            }
        }
    }

    cout << "\nArray yang diinputkan: "<<endl;
    for (int i = 0; i < x; i++) {
        for (int j =0; j < y; j++){
            for (int k = 0; k < z; k++) {
                cout <<"array [" << i << "][" << j << "][" << k <<"] = " << array[i][j][k] <<endl;
            }
        }

    }
    return 0;

}