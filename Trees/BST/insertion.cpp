#include<bits/stdc++.h>

using namespace std;

class BST {
public:
    int data;
    BST * left;
    BST * right;

    BST();
    BST(int);
    BST* insert(BST * ,int);
    void inorder(BST*);
};

BST ::BST() : data(0), left(NULL), right(NULL) {}

BST ::BST(int val) {
        data = val;
        left = right = NULL;
    }

BST* BST:: insert (BST* root, int key ) {
    BST * n = new BST(key);

    if(!root)
        return n;
    
    if(key > root->data)
        root->right = insert(root->right, key);
    
    else if(key < root->data) 
        root->left = insert(root->left, key);
    
    return root;
}

void BST::inorder(BST* root) {
    if(!root) 
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    BST b, *root = NULL; 
    root = b.insert(root, 50); 
    b.insert(root, 30); 
    b.insert(root, 20); 
    b.insert(root, 40); 
    b.insert(root, 70); 
    b.insert(root, 60); 
    b.insert(root, 80); 
  
    b.inorder(root); 
    return 0; 
}