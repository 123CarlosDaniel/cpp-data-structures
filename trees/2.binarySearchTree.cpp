#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

void Insert(Node** root, int data) {
  Node* parent = *root;
  Node* temp = new Node();
  temp->data = data;
  temp->left = temp->right = NULL;
  if (*root == NULL) {
    *root = temp;
    return;
  }
  while (true) {
    if (data <= parent->data) {
      if (parent->left == NULL) break;
      parent = parent->left;
      continue;
    } else {
      if (parent->right == NULL) break;
      parent = parent->right;
      continue;
    }
  }
  if ( data <= parent->data ) {
    parent->left = temp;
  } else {
    parent->right = temp;
  }  
}


bool Search(Node* root, int data) {
  if (root == NULL) {
    return false;
  } 
  else if ( root->data == data) return true; 
  else if ( data <= root->data ) {
    return Search(root->left, data);
  } else return Search(root->right, data); 
}

bool Search2(Node* root, int data) {
  while (root != NULL) {
    if (data = root->data) return true;
    if (data <= root->data) {
      root = root->left;
    } else {
      root = root->right;
    } 
  }
  return false;
}

int FindMin(Node* root ) {
  if (root == NULL) {
    cout<<"Error: Tree is empty"<<endl;
    return -1;
  }
  else if ( root->left == NULL) {
    return root->data;
  }
  return FindMin(root->left);
}

int FindMin2(Node* root) {
  while (root != NULL) {
    if (root->left == NULL) {
      return root->data;
    }
    root = root->left;
  }
  cout<<"Error : Tree is empty"<<endl;
  return -1;
}

int FindHeight(Node* root) {
  if (root == NULL) {
    return -1;
  }
  return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}
int main() {
  Node* root = NULL;
  Insert(&root, 12);
  Insert(&root, 4);
  Insert(&root, 6);
  Insert(&root, 8);
  Insert(&root, 1);
  cout<<Search(root,4)<<endl;
  cout<<Search(root,5)<<endl;
  cout<<"Search 6 "<<Search2(root, 6)<<endl;
  cout<<"Min : "<<FindMin(root)<<endl;
  cout<<"Min2 : "<<FindMin2(root)<<endl;
  cout<<"Height : "<<FindHeight(root)<<endl;
}