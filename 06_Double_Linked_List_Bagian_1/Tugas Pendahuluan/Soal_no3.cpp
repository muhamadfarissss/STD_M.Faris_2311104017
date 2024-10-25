#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *prev;
    Node *next;
};
class doubleLinkedList {
public:
    Node *head;
    Node *tail;
    doubleLinkedList() : head(nullptr), tail(nullptr){}
    void insertLast(int value){
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if(tail == nullptr){
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    void tampilDariDepan(){
        if (head == nullptr){
            cout << "dftar ksoong";
            return;
        }
        Node *temp = head;
        cout << "Daftar elemen dari depan ke belakang: ";
        while (temp != nullptr){
            cout << temp->data;
            if(temp->next != nullptr){
                cout << "<->";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    void tampildariBelakang(){
        if (tail == nullptr){
            cout << "daftar ksoogn";
            return;
        }
        Node *temp = tail;
        cout << "Daftar elemen dari belakang ke depan: ";
        while (temp != nullptr){
            cout << temp->data;
            if(temp->prev != nullptr){
                cout << "<->";
            }
            temp = temp->prev;
        }
        cout << endl;
    }

};
int main(){
    doubleLinkedList dll;
    int elemen;

    for (int i = 1; i <= 4;i++ ){
        cout << "Masukan elemen ke-" << i << ":";
        cin >> elemen;
        dll.insertLast(elemen);

    }
    dll.tampilDariDepan();

    dll.tampildariBelakang();

    return 0;
}