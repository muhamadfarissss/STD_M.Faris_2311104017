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
    void tamplikanList(){
        Node *temp = head;
        while (temp != nullptr){
            cout << temp -> data << "->";
            temp = temp-> next;
        }
        cout << "NULL\n";
    }
    void bubbleSortList(){
        if (head == nullptr){
            return;
        }
        bool swapped;
        Node *current;
        Node *lastptr = nullptr;

        do {
            swapped = false;
            current = head;

            while (current ->next != lastptr){
                if (current-> data > current->next->data){
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
            lastptr = current;
        } while (swapped);
    }
};

int main(){
    LinkedList List;
    int elemen;

    cout << "Masukan 5 elemen int ke list:\n";
    for (int i = 0; i < 5; i++){
        cout <<"Elemen ke-" << i +1 << ":";
        cin >> elemen;
        List.tambahElemen(elemen);
    }

    cout << "list sebelum diurutkan:\n";
    List.tamplikanList();

    List.bubbleSortList();

    cout << "list setelah diurutkan: \n";
    List.tamplikanList();

    return 0;
}