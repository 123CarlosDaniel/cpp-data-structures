#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;
struct Node {
  int data;
  Node* next;
};


void Print(Node* headPointer) {
  cout<<"Data : ";
  while (headPointer != NULL)
  {
    cout<<headPointer->data<<" ";
    headPointer = headPointer->next;
  }
  cout<<endl;
}

#endif