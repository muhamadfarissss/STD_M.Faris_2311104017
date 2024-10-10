#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++ ){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void tukarArray (int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}
void tukarpointer (int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(){
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int a = 10, b = 20;
    int *ptr1 = &a, *ptr2 = &b;

    cout << "Array 1 sebelum ditukar:" << endl;
    tampilkanArray(array1);

    cout << "Array 2 sebelum ditukar:" << endl;
    tampilkanArray(array2);

    tukarArray(array1, array2, 1, 1);

    cout << "Array 1 setelah ditukar:" << endl;
    tampilkanArray(array1);

    cout << "Array 2 setelah ditukar:" << endl;
    tampilkanArray(array2);

    cout << "nilai sebelum pointer ditukar : ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl;
    tukarpointer(ptr1, ptr2);
    cout << "nilai setelah pointer ditukar : ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl;

    return 0;

}