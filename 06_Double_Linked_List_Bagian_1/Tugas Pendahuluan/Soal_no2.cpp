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
    void deletefirst(){
        if (head == nullptr){
            cout << "daftar kosogn tidak daapat menghapus";
            return;
        }
        Node *temp = head;
        if (head == tail){
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    void deleteLast(){
        if (tail == nullptr){
            cout << "Dftar ksoogn, tidak dapat menghapus";
            return;
        }
        Node *temp = tail;
        if (head == tail){
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
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
    int elemenPertama, elemenKedua, elemenKetiga;
    cout << "Masukan elemen pertama: ";
    cin >> elemenPertama;
    dll.insertLast(elemenPertama);

    cout << "Masukan elemen kedua diawal: ";
    cin >> elemenKedua;
    dll.insertLast(elemenKedua);

    cout << "Masukan elemen ketiga diakhir: ";
    cin >> elemenKetiga;
    dll.insertLast(elemenKetiga);

    dll.tampil();
    dll.deletefirst();
    dll.deleteLast();

    cout << "daftar setelah penghapusan";
    dll.tampil();

    return 0;
}