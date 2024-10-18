#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void insertDepan(Node *& head, int nilai){
    Node * newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}
void insertBelakang (Node *& head, int nilai){
    Node *newNode = new Node();
    newNode-> data = nilai;
    newNode-> next = nullptr;

    if (head == nullptr){
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool cariNode(Node *head, int nilai){
    Node *temp = head;
    while (temp != nullptr){
        if (temp-> data == nilai) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int hitungpanjang(Node *head){
    int panjang = 0;
    Node *temp = head;
    while (temp != nullptr){
        panjang++;
        temp = temp->next;
    }
    return panjang;
}
int main(){
    Node *head = nullptr;

    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);

    int cariNilai = 20;
    if(cariNode(head, cariNilai)){
        cout << "Node dengan nilai " << cariNilai << " ditemukan" <<endl;
    } else {
        cout << "Node dengan nilai: " << cariNilai << "tidak ditemukan" <<endl;
    }

    cout << "Panjang linked list: " << hitungpanjang(head)<< endl;

    return 0;
}