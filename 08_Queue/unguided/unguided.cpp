#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* next;
};

class Queue {
private:
    Mahasiswa* front;
    Mahasiswa* back;
    int count;

public:
    Queue() : front(nullptr), back(nullptr), count(0) {}

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(string nama, int nim) {
        Mahasiswa* newNode = new Mahasiswa{nama, nim, nullptr};
        if (isEmpty() || nim < front->nim) {
            newNode->next = front;
            front = newNode;
            if (back == nullptr) {
                back = newNode;
            }
        } else {
            Mahasiswa* current = front;
            while (current->next != nullptr && current->next->nim <= nim) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == nullptr) {
                back = newNode;
            }
        }
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Mahasiswa* temp = front;
            front = front->next;
            delete temp;
            count--;
            if (isEmpty()) {
                back = nullptr;
            }
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Mahasiswa* temp = front;
            cout << "Data antrian mahasiswa (berdasarkan prioritas NIM):" << endl;
            while (temp != nullptr) {
                cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    Queue q;
    int jumlahMahasiswa;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        string nama;
        int nim;

        cout << "\nMasukkan nama mahasiswa: ";
        cin >> nama;
        cout << "Masukkan NIM mahasiswa: ";
        cin >> nim;

        q.enqueue(nama, nim);
    }

    cout << "\nData antrian mahasiswa setelah diurutkan berdasarkan NIM:\n";
    q.viewQueue();

    return 0;
}
