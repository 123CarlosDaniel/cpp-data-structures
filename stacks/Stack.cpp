#include "Stack.h"
#include <iostream>

using namespace std;

void Stack::Print(){
  Node* head = this->head;
  if (head == NULL) {
    cout<<"Stack is empty"<<endl;
    cout<<"Stack lenght : "<< this->lenght<<endl;
    return;
  }
  cout<<"Data : ";
  while (head != NULL){
    cout<<head->data<<" ";
    head = head->next; 
  }
  cout<<endl;
}

void Stack::Push(int data) {
  Node* temp = new Node(data);
  temp->next = this->head;
  this->head = temp;
  ++(this->lenght);
}

void Stack::Pop() {
  Node* deleted = this->head;
  this->head = deleted->next;
  delete deleted;
}