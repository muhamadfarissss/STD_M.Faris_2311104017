#include <iostream>
#include <string>
using namespace std;

struct Node {
    int idBuku;
    string judulBuku;
    string penulis;
    Node *prev;
    Node *next;
};

class doubleLinkedList {
public:
    Node *head;
    Node *tail;

    doubleLinkedList() : head(nullptr), tail(nullptr) {}

    void tambahBuku(int id, const string& judul, const string& penulis){
        Node *newNode = new Node();
        newNode->idBuku = id;
        newNode->judulBuku = judul;
        newNode->penulis = penulis;
        newNode-> next = nullptr;
        newNode->prev = tail;

        if (tail == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Buku dengan ID " << id << "ditemukan\n";
    }

    void tampilDariAwal(){
        if (head == nullptr){
            cout << "Daftar buku kosong\n";
            return;
        }
        Node *temp = head;
        cout <<"daftar buku dari awal sampai akhir: \n";
        while (temp != nullptr){
            cout << "ID Buku: " << temp->idBuku
                 << ", Judul: " << temp->judulBuku
                 << ", Penulis: " <<temp->penulis <<endl;
            temp = temp->next;
        }
    }

    void tampilDariAkhir(){
        if (tail == nullptr){
            cout << "daftar buku kosong\n";
            return;
        }
        Node *temp = tail;
        cout << "daftar buku dari ahir ke awal: \n";
        while (temp != nullptr){
            cout  << "ID Buku: " << temp->idBuku
                 << ", Judul: " << temp->judulBuku
                 << ", Penulis: " <<temp->penulis <<endl;
            temp = temp->prev;
        }
    }
};
int main(){
    doubleLinkedList dll;

    dll.tambahBuku(1, "ppppp", "oooooo");
    dll.tambahBuku(2, "yyyyyy", "rrrrr");
    dll.tambahBuku(3, "hhhhh", "ddddd");

    cout << endl;

    dll.tampilDariAwal();

    cout << endl;

    dll.tampilDariAkhir();

    return 0;
}