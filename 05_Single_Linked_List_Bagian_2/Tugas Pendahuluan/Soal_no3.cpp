#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
class LinkedList{
public:
    Node * head;

    LinkedList(){
        head = nullptr;
    }
    void insertSorted(int nilai){
        Node *newNode = new Node();
        newNode -> data = nilai;
        newNode -> next = nullptr;

        if(head == nullptr || head-> data >= newNode->data){
            newNode->next = head;
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != nullptr && current->next->data < newNode->data){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    void tampilkanList(){
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList list;
    int elemen;
    cout << "Masukkan 4 elemen int ke list secara rurut:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> elemen;
        list.insertSorted(elemen);  
    }
    cout << "\nList setelah memasukkan 4 elemen:\n";
    list.tampilkanList();

    cout << "\nMasukkan elemen int yang ingin ditambahkan: ";
    cin >> elemen;
    list.insertSorted(elemen);

    cout << "\nList setelah menambahkan elemen baru:\n";
    list.tampilkanList();

    return 0;
}