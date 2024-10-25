#include <iostream>
#include <string>

using namespace std;

struct Node {
    int NIM;
    string Nama;
    Node *next;
};

struct LinkedList{
    Node *head;

    LinkedList(){
        head = nullptr;
    }

    void tambahMahasiswa(int nim, string nama){
        Node *newNode = new Node();
        newNode-> NIM = nim;
        newNode-> Nama = nama;
        newNode-> next = nullptr;

        if (head == nullptr){
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void cariMahasiswa(int nim){
        Node *temp = head;
        while (temp != nullptr){
            if(temp->NIM == nim){
                cout << "Mahasiswa ditemukan: " <<temp->Nama<< "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Mahasiswa dengan NIM " << nim << "tidak ditemukan.\n";
    }

    void tampilkanMahasiswa(){
        if (head == nullptr){
            cout << "daftatr mahasiswa kosong.\n";
            return;
        }
        Node *temp = head;
        while (temp != nullptr){
            cout << "NIM: " << temp->NIM << ", Nama: " <<temp->Nama<<"\n";
            temp = temp->next;
        }
    }
};

int main(){
    LinkedList listMahasiswa;

    listMahasiswa.tambahMahasiswa(23, "pppppp");
    listMahasiswa.tambahMahasiswa(24, "ooooooo");
    listMahasiswa.tambahMahasiswa(25, "kkkkkk");


    cout << "daftar mahasiswa:\n";
    listMahasiswa.tampilkanMahasiswa();

    cout << "\npencarian mahasiswa\n";
    listMahasiswa.cariMahasiswa(23);
    listMahasiswa.cariMahasiswa(30);

    return 0;
}