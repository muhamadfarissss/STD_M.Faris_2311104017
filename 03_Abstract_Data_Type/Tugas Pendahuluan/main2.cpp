#include <iostream>

using namespace std;

int main(){
    int a = 15;
    int *ptr = &a;
    cout << "nilai a = " << a << endl;
    cout << "nilai yang ditunjuk oleh pointer adalah = " << *ptr << endl;

}