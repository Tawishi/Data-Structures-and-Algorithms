#include<bits/stdc++.h>

using namespace std;

class node {
 public:
    int data;
    node * left;
    node * right;

    node(int value ) {
        data = value;
        left = right = NULL;
    }
};

void inorder(node * root) {
    stack<node*> s;
    node * current = root;

    while(current != NULL || s.empty()==false) {
        while(current != NULL) {
            s.push(current);
            current = current->left;
        }
        current=s.top();
        cout<<current->data<<" ";
        s.pop();
        current = current->right;
    }
}

void preorder(node * root) {
    stack<node*> s;
    node * current = root;
    s.push(current);
    while(s.empty() == false) {
        current = s.top();
        cout<<current->data<<" ";
        s.pop();
        if(current->right)
            s.push(current->right);
        if(current->left)
            s.push(current->left);
    }
}

void postorder(node * root) {
    if(root == NULL)
        return;
    stack<node*> s1,s2;
    node * current = root;
    s1.push(current);

    //entering data from 
    while(s1.empty() == false) {
        current = s1.top();
        s2.push(current);
        s1.pop();
        if(current->left)
            s1.push(current->left);
        if(current->right)
            s1.push(current->right);
    }

    while (!s2.empty()) { 
        current = s2.top(); 
        s2.pop(); 
        cout << current->data << " "; 
    }
}


//wrong because we need the reverse of this: preorder traversal but with right before left

// void postorder(node * root) {
//     stack<node*> s;
//     node * current = root;
//     s.push(current);
//     while(s.empty() == false) {
//         current = s.top();
//         cout<<current->data<<" ";
//         s.pop();
//         if(current->left)
//             s.push(current->left);
//         if(current->right)
//             s.push(current->right);
//     }
// }

int main() {
    node * root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
}