#include <iostream>
#include "BinaryTree.h"
#include "Stack.h"

using namespace std;

// Preorder : D L R
void Preorder(NodeTree* root) {
  if (root == NULL) return;
  cout<<root->data<<" ";
  Preorder(root->left);
  Preorder(root->right);
}

void Inorder(NodeTree* root) {
  if (root == NULL) return;
  Preorder(root->left);
  cout<<root->data<<" ";
  Preorder(root->right);
}

void PostOrder(NodeTree* root) {
  if (root == NULL) return;
  Preorder(root->left);
  Preorder(root->right);
  cout<<root->data<<" ";
}
/*
  Time complexity of all : O(n)
  Space : 
  worst : O(n)
  average : O(logn)
*/

void PreOrder2(NodeTree* root) {
  if (root == NULL) return;
  Stack<NodeTree*> stack;
  stack.Push(root);
  while ( !stack.Empty() ) {
    NodeTree* node = stack.Top();
    cout<<node->data<<" ";
    stack.Pop();
    if (node->right != NULL) {
      stack.Push(node->right);
    }
    if (node->left != NULL) {
      stack.Push(node->left);
    }
  }
}

/*
  Time complxity : O(n)
  Space Complexity : O(logn)
*/
bool IsBstUtil(NodeTree* root, int minVal, int maxVal) {
  if (root == NULL) return true;
  if (root->data > minVal && root->data < maxVal 
    && IsBstUtil(root->left, minVal, root->data) 
    && IsBstUtil(root->right, root->data, maxVal)
  ) return true ;
  return false;
}

bool IsBinarySearchTree(NodeTree* root){
  return IsBstUtil(root, INT_MIN, INT_MAX);
}

NodeTree* FindMin(NodeTree* root) {
  if (root == NULL ) return root;
  if (root->left == NULL) return root;
  return FindMin(root->left);
}

NodeTree* Delete(NodeTree* root, int data) {
  if (root == NULL) return root;
  if ( data < root->data) root->left = Delete(root->left, data);
  else if ( data > root->data) root->right = Delete(root->right, data);
  // data = root->data
  else {
    if ( root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }
    else if ( root->left == NULL) {
      NodeTree* temp = root;
      root = root->right;
      delete temp;
    }
    else if ( root->right == NULL) {
      NodeTree* temp = root;
      root = root->left;
      delete temp;
    }
    else {
      NodeTree* temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }
  return root;
}

int main() {
  BinarySearchTree root;
  root.Insert(4);
  root.Insert(5);
  root.Insert(8);
  root.Insert(1);
  root.Insert(7);
  cout<<root.Search(4)<<endl;
  Preorder(root.GetRoot());
  cout<<endl;
  PreOrder2(root.GetRoot());
  cout<<endl;
  cout<<IsBinarySearchTree(root.GetRoot())<<endl;
  Delete(root.GetRoot(), 8);
  cout<<endl;
  PreOrder2(root.GetRoot());

}