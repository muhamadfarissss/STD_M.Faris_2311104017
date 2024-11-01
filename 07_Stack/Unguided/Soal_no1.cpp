#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool isPalindrom(const string & str){ //fungsi isPalindrom
    stack<char> charStack;//charStack
    string filteredStr;//filteredStr
    for (char ch : str){
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
            if (ch >= 'A' && ch <= 'Z'){
                ch += 'a' - 'A';
            }
            filteredStr += ch;
            charStack.push(ch);
        }
    }
    for (char ch : filteredStr){
        if(charStack.top() != ch){
            return false;
        }
        charStack.pop();
    }
    return true;
}
int main(){
    string input;

    cout << "Masukan kalimat: ";
    getline(cin, input);//input

    if(isPalindrom(input)){
        cout << "Kalimat tersebut adalah palindrom." <<endl;
    } else {
        cout << "kalimat tersebut bukan palindrom" <<endl;
    }
    return 0;
}
// penjelasan
// program meminta user untuk memasukan kalimat melalui konsol dengan getline(cin, input);
// fungsi isPalindrom dipanggi dengan input dari pengguna
// dalam fungsi ini program memeriksa apakah karakter tersebut merupakan huruf (A-Z, a-z), mengonversi huruf kapital menjadi huruf kecil dan Menyimpan karakter yang valid ke dalam string filteredStr dan juga ke dalam stack charStack
//Setelah semua karakter difilter dan disimpan, program memeriksa apakah karakter dari filteredStr sama dengan karakter yang diambil dari charStack (dari atas ke bawah)
//Jika semua karakter cocok, maka string tersebut adalah palindrom
// lalu program akan mencetak apakah kalimatnya palindrom atau bukan