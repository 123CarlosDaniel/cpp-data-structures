#include <iostream>
#include "BynaryTree.h"
#include "Queue.h"

using namespace std;

void LevelOrder(NodeTree* root) {
  if (root == NULL) {
    cout<<"Tree is empty "<<endl;
  }
  Queue<NodeTree*> Q;
  Q.Enqueue(root);
  while (!Q.Empty()){
    NodeTree* current = Q.Front();
    cout<<current->data<<" ";
    if ( current->left != NULL) Q.Enqueue(current->left);
    if ( current->right != NULL) Q.Enqueue(current->right);
    Q.Dequeue();
  }
}

int main() {
  BynarySearchTree* root = new BynarySearchTree();
  root->Insert(4);
  root->Insert(11);
  root->Insert(10);
  root->Insert(5);
  root->Insert(-1);
  root->Insert(2);
  LevelOrder(root->GetRoot());

}