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

// Space Complexity : O(1)
// Time Complexity : O(n) , in the worst case we iterate n times to insert in the 
// last position.
void LinkedList::Insert(int n, int data) {
  Node* head = this->head; // &head != &(this.head)
  Node* temp1 = new Node(data);
  ++(this->lenght);
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

void LinkedList::Push(int data) {
  this->Insert(this->lenght + 1,data);
}

// Space Complexity : O(1) : if we look on the code we don't use any other data 
// structure to storage data in every iteration.
// Time Complexity : O(n) : It has n iterations in the worst case when we want
// to remove the last element of the linked list. 

void LinkedList::Delete(int n) {
  --(this->lenght);
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
// Space Complexity : O(1) , because we don't use any extra memory that is gonna persists 
// trough every iteration.
// Time Complexity : O(n) , this is simple we are traversing the linkedList, 
// so time complexity is O(n) , where n is the lenght of the linked list.
void LinkedList::Reverse() {
  cout<<"Reversing list"<<endl;
  Node* current = this->head;
  Node* prev = NULL;
  while (current != NULL)
  {
    Node* next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  this->head = prev;
}