#include<bits/stdc++.h>
using namespace std;

class BST {
public:
    int data;
    BST * left;
    BST * right;

    BST();
    BST(int);
    BST * delete_node(BST* ,int key);
};

BST :: BST() : data(0), right(NULL), left(NULL) {}

BST :: BST(int value) : data(value), right(NULL), left(NULL) {}

BST * delete_node(BST * root, int key) {
    if(root==NULL)
        return root;

    if(key < root->data)
        root->left=delete_node(root->left, key);

    else if(key > root->data)
        root->right=delete_node(root->right, key);

    
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key;
        inorder(root->right);
    }
}

int main() {
    return 0;
}