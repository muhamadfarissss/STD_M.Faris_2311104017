#include <iostream>

using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull(){
    return top == maksimal;
}
bool isEmpty(){
    return top == 0;
}
void pushArrayBuku(string data){
    if (isFull()){
        cout << "data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top ++;
    }
}
void popArrayBuku(){
    if (isEmpty()){
        cout << "tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}
void peekArrayBuku(int posisi){
    if(isEmpty()){
        cout << "tidak ada yang bisa dilihat" << endl;
    } else {
        int index = top - posisi;
        if (index >= 0 && index < top){
            cout << "posisi ke " << posisi << "adalah " << arrayBuku[index];
        } else {
            cout << "psosoi diluar jangkauan" << endl;
        }

    }
}
int countStack(){
    return top;
}
void changeArrayBuku(int posisi, string data){
    int index = top - posisi;
    if (index >= 0 && index < top){
        arrayBuku[index] = data;
    } else {
        cout << "posisi mlebih data yang ada" << endl;
    }
}
void destroyArrayBuku(){
    for (int i = top -1; i >=0; i--){
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArrayBuku(){
    if (isEmpty()){
        cout << "tidak ada data yang dicetak";
    } else {
        for (int i = top -1; i >= 0; i--){
        cout << arrayBuku[i] << endl;
        }
    }
}
int main(){
    pushArrayBuku("kalkulus");
    pushArrayBuku("struktur data");
    pushArrayBuku("matematika diskrti");
    pushArrayBuku("multimedia");
    pushArrayBuku("inggris");

    cetakArrayBuku();
    cout << "\n" << endl;

    cout << "apakahd ata stack penuh? " << (isFull() ? "Ya" : "tidak") << endl;
    cout << "apakahd ata stack kosong? " << (isEmpty() ? "Ya" : "tidak") << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "baha jerman");
    cetakArrayBuku();
    cout << "\n" << endl;

    destroyArrayBuku();
    cout << "top stelah destroy: " << top << endl;
    cetakArrayBuku();

    return 0; 
}