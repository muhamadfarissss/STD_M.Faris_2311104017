#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

string balikKata(const string & kata){
    stack<char> stackKarakter;
    for (char ch : kata){
        stackKarakter.push(ch);
    }
    string kataTerbalik = " ";
    while (!stackKarakter.empty()){
        kataTerbalik += stackKarakter.top();
        stackKarakter.pop();
    }
    return kataTerbalik;
}
int main(){
    string input;
    cout << "Masukan kalimat: ";
    getline(cin, input);

    stack<string> stackKata;
    stringstream ss(input);
    string kata;

    while (ss >> kata){
        stackKata.push(balikKata(kata));
    }
    cout << "Array Stack:\n";

    cout << "Data: ";
    while (!stackKata.empty()){
        cout << stackKata.top() << " ";
        stackKata.pop();
    }
    cout <<endl;

    return 0;
}
//penjelasan
//Output dari program ini adalah tampilan kata-kata dalam kalimat yang telah dibalik urutannya. 
//Misalnya, jika pengguna memasukkan kalimat Telkom Purwokerto, program akan menghasilkan output otrekowruP mokleT, menampilkan setiap kata dalam bentuk yang terbalik.
//Program meminta pengguna memasukkan kalimat
//Menggunakan stringstream untuk memisahkan kalimat menjadi kata-kata
//Setiap kata yang diambil dari stringstream diproses dengan fungsi balikKata, dan hasilnya disimpan dalam stack stackKata
//lalu menampilkan outputnya