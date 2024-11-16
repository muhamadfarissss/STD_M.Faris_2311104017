#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};
bool is_valid_bst(Pohon *node, int min_val, int max_val) {
    if (!node) return true;

    if (node->data < min_val || node->data > max_val)
        return false;

    return is_valid_bst(node->left, min_val, node->data - 1) && 
           is_valid_bst(node->right, node->data + 1, max_val);
}
int main(){
    Pohon* root = new Pohon{10, NULL, NULL, NULL};
    Pohon* left = new Pohon{5, NULL, NULL, root};
    Pohon* right = new Pohon{15, NULL, NULL, root};
    root->left = left;
    root->right = right;
    cout << "Is this a valid BST? " << (is_valid_bst(root, INT_MIN, INT_MAX) ? "Yes" : "No") << endl;
}
