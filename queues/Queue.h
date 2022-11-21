#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = NULL;
  }
  ~Node() {
    cout<<"Deleting node "<<this<<endl;
  }
};

class Queue {
  private: 
    Node* front;
    Node* rear;
  public:
    Queue(){
      front = rear = NULL;
    };
    Queue(int data) {
      front = rear = new Node(data);
    }
    ~Queue() {
      Node* temp = this->front;
      while (temp != NULL){
        Node* next = temp->next;
        delete temp;
        temp = next; 
      }
      cout<<"Deleting Queue"<<endl;
    }
    void Enqueue(int data);
    void Dequeue();
    int Front();
    void Print();
};


#endif