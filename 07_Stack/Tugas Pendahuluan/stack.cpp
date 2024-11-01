#include "stack.h"
#include <iostream>
using namespace std;

void createStack(stack &S) {
    S.Top = 0;
}
bool isEmpty(stack S) {
    return S.Top == 0;
}
bool isFull(stack S) {
    return S.Top == MAX_SIZE;
}
void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.Top++;
        S.info[S.Top] = x;
    }
}
int pop(stack &S) {
    infotype x = '\0';
    if (!isEmpty(S)) {
        x = S.info[S.Top];
        S.Top--;
    }
    return x;
}
void printInfo(stack S) {
    for (int i = S.Top; i > 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}
