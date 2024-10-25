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
    void insertFirst(int value){
        Node * newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head == nullptr){
            tail = newNode;
        } else {
            head->prev = newNode;
        }
        head = newNode;
    }
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
    void tampil(){
        if (head == nullptr){
            cout << "Daftar kosong\n";
            return;
        }
        Node *temp = head;
        cout << "Daftar anggota List: ";
        while (temp != nullptr){
            cout << temp->data;
            if (temp->next != nullptr){
                cout << "<->";
            }
            temp = temp->next;
        }
        cout <<endl;
    }
};
int main(){
    doubleLinkedList dll;

    int elemenPertama, elemenAwal, elemenAkhir;

    cout << "Masukan elemen pertama: ";
    cin >> elemenPertama;
    dll.insertLast(elemenPertama);

    cout << "Masukan elemen kedua diawal: ";
    cin >> elemenAwal;
    dll.insertFirst(elemenAwal);

    cout << "Masukan elemen ketiga diakhir: ";
    cin >> elemenAkhir;
    dll.insertLast(elemenAkhir);

    dll.tampil();

    return 0;
}