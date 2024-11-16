#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;
void init(){
    root = NULL;
}
bool isEmpty(){
    return root == NULL;
}
void buatNode(char data){
    if(isEmpty()){
        root = new Pohon {data, NULL, NULL, NULL};
        cout << "\nNode " << data << "Berhasil dibuat menjadi root" << endl;
    } else {
        cout << "Phpn sudah dibuat" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node){
    if(isEmpty()){
        cout << "Buat tree terlebih dahulu "<< endl;
        return NULL;
    }
    if (node ->left != NULL){
        cout << "\nNode" << node ->data <<"sudah ada child kiri" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node -> left = baru;
    cout << "\nNode " << data << "Berhasil ditambahkan ke child kiri" << endl;
    return baru;
}
Pohon *insertRight(char data, Pohon *node){
    if(isEmpty()){
        cout << "Buat tree terlebih dahulu" << endl;
        return NULL;
    }
    if(node->right != NULL){
        cout << "\nNode " << node->data << "sudah ada child kanan" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node -> right = baru;
    cout << "\nNode " << data << "berhasil ditambahkan ke child kanan" << endl;
    return baru;
}
void update(char data, Pohon *node){
    if(isEmpty()){
        cout << "\nBuat tree terlebih dahulu" << endl;
        return;
    }
    if(!node){
        cout << "\nNode yang ingin diganti tidak ada" << endl;
        return;
    }
    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << "Berhasil diubah menjadi " << data << endl;
}
void retrieve(Pohon *node){
    if(isEmpty()){
        cout << "\nBuat tree terlebih dahulu" << endl;
        return;
    }
    if(!node){
        cout << "\nNode yang ditunjuk tidak ada" << endl;
        return;
    }
    cout << "\nData node : " << node->data << endl;
}
void find (Pohon *node){
    if(isEmpty()){
        cout << "\nBuat tree terlebih dahulu" << endl;
        return;
    }
    if(!node){
        cout << "\nNode yang ditunjuk tidak ada" << endl;
        return;
    }
    cout << "\nData node :" << node-> data << endl;
    cout << "Root: " << root->data << endl;
    cout << "Parent: " << (node->parent ? node->parent->data : '(tidak punya parent)') << endl;

    if(node->parent){
        if(node->parent->left == node && node->parent->right)
            cout << "Sibling: " << node->parent->right->data << endl;
        else if(node->parent->right == node && node->parent->left)
            cout << "Sibling: " << node->parent->left->data << endl;
        else 
            cout << "Sibling: (tidak ada sibling)" << endl; 
    }
}
void printChildren(Pohon *node){
    if(!node){
        cout << "\nNode tidak ditemukan" << endl;
        return;
    }
    cout << "Children node " << node->data << ": ";
    if(node->left) cout << node->left->data << ": ";
    if(node->right) cout << node->right->data << ": ";
    cout << endl;
}
void printDescendan(Pohon *node){
    if(!node) return;
    if(node->left){
       cout << node->left->data << " ";
       printDescendan(node->left);
    }
    if(node->right){
        cout << node->right->data << " ";
        printDescendan(node->right);
    }
}
int main(){
    init();
    buatNode('A');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeC = insertRight('C', root);
    insertLeft('D', nodeB);
    insertRight('E', nodeB);
    insertLeft('F', nodeC);
    insertRight('G', nodeC);

    int choice;
    char data;
    Pohon *selectedNode;

    while(true){
        cout << "\nMenu: \n";
        cout << "1. Retrieve Node\n";
        cout << "2. Find Node\n";
        cout << "3. Update Node\n";
        cout << "4. Print Children Node\n";
        cout << "5. print descendant Node\n";
        cout << "6. exit\n";
        cout << "Masukan pilihan: ";
        cin >>choice;

        switch(choice){
            case 1:
                cout << "Masukan node data untuk retrieve: ";
                cin >> data;
                selectedNode = root;
                while(selectedNode && selectedNode->data != data){
                    if(data < selectedNode->data){
                        selectedNode = selectedNode->left;
                    } else {
                        selectedNode = selectedNode->right;
                    }
                }
                retrieve(selectedNode);
                break;
            case 2:
                cout << "masukan data untuk find: ";
                cin >> data;
                selectedNode = root;
                while(selectedNode && selectedNode->data != data){
                    if(data < selectedNode->data){
                        selectedNode = selectedNode->left;
                    } else {
                        selectedNode = selectedNode->right;
                    }
                }
                find(selectedNode);
                break;
            case 3:
                cout << "masukan data untuk find: ";
                cin >> data;
                selectedNode = root;
                while(selectedNode && selectedNode->data != data){
                    if(data < selectedNode->data){
                        selectedNode = selectedNode->left;
                    } else {
                        selectedNode = selectedNode->right;
                    }
                }
                if (selectedNode){
                    cout << "msukan nilai baru untuk node: ";
                    cin>> data;
                    update(data, selectedNode);
                } else {
                    cout << "node tidak ditemukan" << endl;
                }
                break;
            case 4:
                cout << "masukan data untuk find: ";
                cin >> data;
                selectedNode = root;
                while(selectedNode && selectedNode->data != data){
                    if(data < selectedNode->data){
                        selectedNode = selectedNode->left;
                    } else {
                        selectedNode = selectedNode->right;
                    }
                }
                printChildren(selectedNode);
                break;
            case 5:
                cout << "masukan data untuk find: ";
                cin >> data;
                selectedNode = root;
                while(selectedNode && selectedNode->data != data){
                    if(data < selectedNode->data){
                        selectedNode = selectedNode->left;
                    } else {
                        selectedNode = selectedNode->right;
                    }
                }
                cout << "desecndant dari " << selectedNode->data << ": ";
                printDescendan(selectedNode);
                cout << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "pilihan invalid" << endl;
        }
    }
    return 0;
}