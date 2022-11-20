#ifndef BYNARY_TREE_H
#define BYNATY_TREE_H
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

class BynarySearchTree {
  private :
    NodeTree* root;
  public :
    BynarySearchTree() {
      root = NULL;
    }
    BynarySearchTree(int data) {
      root = new NodeTree(data);
    }
    void Insert(int data);
    bool Search(int data);  
    NodeTree* GetRoot() {
      return root;
    }
};

#endif