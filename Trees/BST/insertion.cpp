#include<bits/stdc++.h>

using namespace std;

class node {
public:
    int data;
    node * left;
    node * right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node * insert (node * root, int key) {
    node * n = new node(key);

    if(root==NULL)
        return n;
    
    if(key > root->data)
        root->right = insert(root->right, key);
    
    else if(key < root->data) 
        root->left = insert(root->left, key);
    
    return root;

}

int main() {

}