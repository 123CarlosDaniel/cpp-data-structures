#include <iostream>
#include "LinkedList.h"

using namespace std;

void LinkedList::Print(){
  Node* head = this->head;
  if (head == NULL) {
    cout<<"Lista vacia"<<endl;
    return;
  }
  cout<<"Data : ";
  while (head != NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

void LinkedList::Insert(int n, int data) {
  Node* head = this->head; // &head != &(this.head)
  Node* temp1 = new Node(data);
  if (n == 1) {
    temp1->next = head;
    this->head = temp1;
    return;
  }
  for (int i{1}; i<n-1;i++) {
    head = head->next;
  }
  temp1->next = head->next;
  head->next = temp1;
}

void LinkedList::Delete(int n) {
  Node* head = this->head;
  if (n == 1) {
    this->head = head->next;
    delete head;
    return;
  }
  for (int i{}; i<n-2;i++) {
    head = head->next;
  }
  Node* temp = head->next;
  head->next = temp->next;
  delete temp;
}
