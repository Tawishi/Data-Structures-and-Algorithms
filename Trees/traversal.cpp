#include<iostream>
using namespace std;
class node  { 
public :
  int data; 
  struct node *left; 
  struct node *right;
   node(int value) {
       data = value;
       left = NULL;
       right = NULL;
   }
};

void printPostorder(node *node) {
    if(node == NULL) {
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);

    cout<< node->data <<" ";
}

int main() {
    node * root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout<<"Postorder tree traversal"<<endl;
    printPostorder(root);
}
