#include <iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;

void displayStackOutput(stack &S, const char* elements, int popCount) {
    createStack(S);

    int length = 0;
    while (elements[length] != '\0') length++; 

    for (int i = length - 1; i >= 0; i--) {
        push(S, elements[i]);
    }

    cout << "isi stack awal:\n";
    printInfo(S);

    for (int i = 0; i < popCount; i++) {
        pop(S);
    }
    cout << "isi stack sesudah pop:\n";
    printInfo(S);
}
int main() {
    stack S;
    int lastDigit;
    cout << "Masukan digit terahir NIM: ";
    cin >> lastDigit;

    cout << "Digit terakhir NIM MOD 4 sisa " << (lastDigit % 4) << " :\n";

    switch (lastDigit % 4) {
        case 0:
            displayStackOutput(S, "IFLABJAYA", 5); 
            break;
        case 1:
            displayStackOutput(S, "HALOBANDUNG", 4); 
            break;
        case 2:
            displayStackOutput(S, "PERCAYADIRI", 7); 
            break;
        case 3:
            displayStackOutput(S, "STRUKTURDATA", 8); 
            break;
        default:
            cout << "Invalid input" << endl;
    }

    return 0;
}
