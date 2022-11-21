#ifndef BINARY_TREE_H
#define BINATY_TREE_H
#include <iostream>

struct NodeTree
{
  int data;
  NodeTree* left;
  NodeTree* right;
  NodeTree( int data) {
    this->data = data;
    this->left = this->right = NULL;
  }
};

class BinarySearchTree {
  private :
    NodeTree* root;
  public :
    BinarySearchTree() {
      root = NULL;
    }
    BinarySearchTree(int data) {
      root = new NodeTree(data);
    }
    void Insert(int data);
    bool Search(int data);  
    NodeTree* GetRoot() {
      return root;
    }
};

#endif