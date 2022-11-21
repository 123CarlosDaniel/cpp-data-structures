#include "Queue.h"
#include <iostream>

using namespace std;

void Queue::Print() {
  Node* head = this->front;
  if (head == NULL) {
    cout<<"Queue is empty"<<endl;
    return;
  }
  cout<<"Data : ";
  while( head != NULL) {
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

void Queue::Enqueue(int data) {
  Node* front = this->front;
  Node* rear = this->rear;
  Node* temp = new Node(data);
  if (front == NULL && rear == NULL) {
    this->front = temp;
    this->rear = temp;
    return;
  }
  this->rear->next = temp;
  this->rear = temp;
}

void Queue::Dequeue() {
  Node* front = this->front;
  Node* rear = this->rear;
  if (front == NULL) return;
  if (front == rear) {
    this->front = NULL;
    this->rear = NULL;
    return;
  } else {
    this->front = front->next;  
  }
  delete front;
}

int Queue::Front() {
  return this->front->data;
}