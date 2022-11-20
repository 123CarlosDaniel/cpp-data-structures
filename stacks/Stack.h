#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* next;
  Node(T data) {
    this->data = data;
    this->next = NULL;
  }
  // ~Node(){
  //   cout<<"Deleting node at "<<this<<endl;
  // }
};

template <typename T>
class Stack {
  private:
    Node<T>* head;
    int lenght{};
  public :
    Stack() {
      head = NULL;
    }
    Stack(T data) {
      head = new Node<T>(data);
      lenght++;
    }
    ~Stack() {
      Node<T>* tempHead = head;
      while (tempHead!= NULL){
        Node<T>* next = tempHead->next;
        delete tempHead;
        tempHead = next;
      }
      // cout<<"Deleting Stack head"<<endl;
    }
    void Push( T data);
    void Pop();
    T Top();
    void Print();
};

template <typename T>
void Stack<T>::Print(){
  Node<T>* head = this->head;
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

template <typename T>
void Stack<T>::Push(T data) {
  Node<T>* temp = new Node(data);
  temp->next = this->head;
  this->head = temp;
  ++(this->lenght);
}

template <typename T>
void Stack<T>::Pop() {
  Node<T>* deleted = this->head;
  this->head = deleted->next;
  delete deleted;
}

template <typename T>
T Stack<T>::Top() {
  return this->head->data;
}

#endif