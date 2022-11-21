
#include <iostream>
#include "BinaryTree.h"

using namespace std;



int main() {
  BinarySearchTree* root = new BinarySearchTree();
  root->Insert(4);
  root->Insert(45);
  root->Insert(14);
  bool res = root->Search(14);
  cout<<res<<endl;
}