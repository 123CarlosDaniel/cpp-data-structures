#include <iostream>

using namespace std;

struct BSTNode {
  int data;
  BSTNode* left; 
  BSTNode* right;
};

void Insert(BSTNode** root, int data) {
  if (*root == NULL) {
    BSTNode* newNode = new BSTNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    *root = newNode;
  } else if ( data <= (*root)->data){
    Insert(&((*root)->left), data); 
  } else {
    Insert(&((*root)->right), data);
  }
}

bool Search(BSTNode* root, int data) {
  if (root == NULL) {
    return false;
  } 
  else if ( root->data == data) return true; 
  else if ( data <= root->data ) {
    return Search(root->left, data);
  } else return Search(root->right, data); 
}
int main() {
  BSTNode* root = NULL;
  Insert(&root, 12);
  Insert(&root,14);
  Insert(&root,452);
  cout<<Search(root, 13)<<endl;
}