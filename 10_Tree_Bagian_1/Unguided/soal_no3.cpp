#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};
int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;  
    if (!node->left && !node->right) return 1;  
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right); 
}
Pohon* buatNode(char data, Pohon* parent = nullptr) {
    Pohon* newNode = new Pohon{data, nullptr, nullptr, parent};
    return newNode;
}
int main() {
    Pohon *root = buatNode('A');
    Pohon *nodeB = buatNode('B', root);
    Pohon *nodeC = buatNode('C', root);
    root->left = nodeB;
    root->right = nodeC;

    Pohon *nodeD = buatNode('D', nodeB);
    Pohon *nodeE = buatNode('E', nodeB);
    nodeB->left = nodeD;
    nodeB->right = nodeE;

    Pohon *nodeF = buatNode('F', nodeC);
    Pohon *nodeG = buatNode('G', nodeC);
    nodeC->left = nodeF;
    nodeC->right = nodeG;
    cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;

    return 0;
}
