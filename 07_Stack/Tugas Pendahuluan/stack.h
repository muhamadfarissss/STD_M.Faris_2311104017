
#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 15
typedef char infotype;

struct stack {
    infotype info[MAX_SIZE + 1];
    int Top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
int pop(stack &S);
void printInfo(stack S);

#endif
