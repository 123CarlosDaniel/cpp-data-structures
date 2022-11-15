#include <iostream>
#include "utils.h"
using namespace std;

void Push(Node** headPointer, int data ) { 
  // Creating the new Node to insert
  Node* temp = new Node();
  temp->data = data;
  temp->next = *headPointer;
  *headPointer = temp;
}

void Pop(Node** headPointer) {
  Node* deleted = *headPointer;
  *headPointer = deleted->next;
  delete deleted;
  cout<<"Deleting node element"<<endl;
}

int main() {
  Node* headPointer = NULL; // empty linked list
  Push(&headPointer, 4);
  Push(&headPointer, 4);
  Push(&headPointer, 4);
  Push(&headPointer,5);
  Print(headPointer);
  Pop(&headPointer);
  Print(headPointer);
  Push(&headPointer,86);
  Print(headPointer);
}