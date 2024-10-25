#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
class LinkedList{
public:
    Node *head;
    LinkedList(){
        head = nullptr;
    }
    void tambahElemen(int nilai){
        Node *newNode = new Node();
        newNode->data = nilai;
        newNode->next = nullptr;
        if(head == nullptr){
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr){
                temp= temp->next;
            }
            temp->next = newNode;
        }
    }
    void searchElement(int nilai){
        Node *current = head;
        int position = 1;
        bool found = false;
        while (current != nullptr){
            if (current -> data == nilai){
                found = true;
                cout << "Elemen " << nilai << "ditemukan di alamat " << current << " urutan ke: " << position << endl;
                break;
            }
            current = current->next;
            position++;
        }
        if (!found) {
            cout << "Elemen " << nilai << "tidak ditemukan di list\n";
        }
    }
    void tampilkanList(){
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
       
    }
};

int main(){
    LinkedList list;
    int nilaicari;

    cout << "Masukan 6 elemen int :\n";
    for (int i = 0; i < 6; i++){
        int elemen;
        cout << "Elemen ke: " << i + 1 << ": ";
        cin >> elemen;
        list.tambahElemen(elemen);
    }

    cout << "\nelemen dalam list:\n";
    list.tampilkanList();

    cout << "Masukan nilai yang dicari: ";
    cin>> nilaicari;

    list.searchElement(nilaicari);

    return 0;
}