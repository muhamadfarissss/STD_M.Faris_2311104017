#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "Masukan jumlah elemen array: ";
    cin >> n;

    int array[n];

    cout << "Masukan" << n << "elemen array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int maksimum = array[0];
    int minimum = array [0];
    int jumlah = 0;

    for (int i = 0; i < n; i++){
        if (array[i] > maksimum){
            maksimum = array[i];
        }
        if (array[i] < minimum){
            minimum = array[i];
        }
        jumlah += array[i];
    }

    float rata_rata = (float)jumlah / n;
    cout << "nilai maksimum: " << maksimum << endl;
    cout << "Nilai minimum: " << minimum << endl;
    cout << "nilai rata-rata: " << rata_rata << endl;

    return 0;
}