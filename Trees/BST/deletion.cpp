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


    //find the node to be deleted
    if(key < root->data) {
        root->left=delete_node(root->left, key);
        return root;
    }

    else if(key > root->data) {
        root->right=delete_node(root->right, key);
        return root;
    }


    //identify the type of deletion, based on no. of children

    //1 child
    if(root->left == NULL) {
        BST * temp = root->right;
        delete root;
        return temp;
    }

    else if(root->right == NULL) {
        BST * temp = root->left;
        delete root;
        return temp;
    }

    //2 children
    else {
        BST * parent = root;
        BST * successor = root->right;

        //find key to replace key to be deleted
        while(successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }
    
    //if there is a successor
    if(parent != root) 
        parent->left = successor->right;
    //if no successor
    else 
        parent->right = successor->right;

    //exchanging keys
    root->data = successor->data;

    delete successor;
    return root;
    }
    
}

void inorder(BST * root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data<<" ";
        inorder(root->right);
    }
}

BST * insert(BST * root,int key) {

    BST * node = new BST(key);

    if(!root)
        return node;
    
    else if(key > root->data) {
        root->right = insert(root->right,key);
    }

    else if(key < root->data) {
        root->left = insert(root->left,key);
    }

    return root;
}

int main() {
      BST* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = delete_node(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = delete_node(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = delete_node(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    return 0;
}