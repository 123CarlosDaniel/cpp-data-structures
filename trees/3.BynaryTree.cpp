
#include <iostream>
#include "BynaryTree.h"

using namespace std;



int main() {
  BynarySearchTree* root = new BynarySearchTree();
  root->Insert(4);
  root->Insert(45);
  root->Insert(14);
  bool res = root->Search(14);
  cout<<res<<endl;
}