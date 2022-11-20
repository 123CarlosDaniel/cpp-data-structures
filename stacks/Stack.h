#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
  ~Node(){
    cout<<"Deleting node at "<<this<<endl;
  }
};

class Stack {
  private:
    Node* head;
    int lenght{};
  public :
    Stack() {
      head = NULL;
    }
    Stack(int data) {
      head = new Node(data);
      lenght++;
    }
    ~Stack() {
      Node* tempHead = head;
      while (tempHead!= NULL){
        Node* next = tempHead->next;
        delete tempHead;
        tempHead = next;
      }
      cout<<"Deleting Stack head"<<endl;
    }
    void Push( int data);
    void Pop();
    void Print();
};

#endif