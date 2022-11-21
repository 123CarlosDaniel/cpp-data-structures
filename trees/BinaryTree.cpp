#include <iostream>
#include "BinaryTree.h"
using namespace std;

void BinarySearchTree::Insert(int data) {
  NodeTree* temp1 = this->root;
  NodeTree* newNode = new NodeTree(data);
  if (temp1 == NULL ) {
    this->root = newNode;
    return;
  } 
  while (true) {
    if ( data <= temp1->data ) {
      if (temp1->left == NULL) {
        temp1->left = newNode;
        break;
      } 
      temp1 = temp1->left;
    }
    else {
      if ( temp1->right == NULL) {
        temp1->right = newNode;
        break;
      }
      temp1 = temp1->right;
    }
  }
}

bool BinarySearchTree::Search(int data) {
  NodeTree* root = this->root;
  while ( true ) {
    if ( root == NULL) {
      cout<<"Empty BynaryTree"<<endl;
      return false;
    }
    if ( root->data = data) return true;
    if ( data <= root->data) {
      root = root->left;
    }
    else {
      root = root->right;
    }
  }
}