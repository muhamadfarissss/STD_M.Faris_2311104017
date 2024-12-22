#include <iostream>
using namespace std;

int main(){
    int jumlahsimpul, jumlahsisi;

    cout << "Masukan jumlah simpul: ";
    cin >> jumlahsimpul;
    cout << "Masukan jumlah sisi: ";
    cin >> jumlahsisi;

    int adjancencyMatrix[100][100] = {0};
    cout << "Masukan pasangan simpul: " << endl;
    for(int i =0; i< jumlahsisi; ++i){
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;

        adjancencyMatrix[simpul1 - 1][simpul2 - 1] = 1;
        adjancencyMatrix[simpul2 - 1][simpul1 - 1] = 1;
    }

    cout << "Adjacency Matrix: " << endl;
    for (int i = 0; i < jumlahsimpul; ++i){
        for(int j = 0; j < jumlahsimpul; ++j){
            cout << adjancencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}