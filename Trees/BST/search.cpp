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

node * search (node * root, int key) {
    if(root->data == key)
        return root;
    
    else if(key < root->data) {
        return search(root->left, key);
    }

    return search(root->right,key);

}

int main() {
     
}