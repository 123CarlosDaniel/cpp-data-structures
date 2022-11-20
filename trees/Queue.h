#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* next;
  Node(T data) {
    this->data = data;
    next = NULL;
  }
  ~Node() {
    // cout<<"Deleting node "<<this<<endl;
  }
};

template <typename T>
class Queue {
  private: 
    Node<T>* front;
    Node<T>* rear;
  public:
    Queue(){
      front = rear = NULL;
    };
    Queue(T data) {
      front = rear = new Node(data);
    }
    ~Queue() {
      Node<T>* temp = this->front;
      while (temp != NULL){
        Node<T>* next = temp->next;
        delete temp;
        temp = next; 
      }
      // cout<<"Deleting Queue"<<endl;
    }
    void Enqueue(T data);
    void Dequeue();
    T Front();
    void Print();
    bool Empty();
};

template <typename T>
void Queue<T>::Print() {
  Node<T>* head = this->front;
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

template <typename T>
void Queue<T>::Enqueue(T data) {
  Node<T>* front = this->front;
  Node<T>* rear = this->rear;
  Node<T>* temp = new Node<T>(data);
  if (front == NULL && rear == NULL) {
    this->front = temp;
    this->rear = temp;
    return;
  }
  this->rear->next = temp;
  this->rear = temp;
}

template <typename T>
void Queue<T>::Dequeue() {
  Node<T>* front = this->front;
  Node<T>* rear = this->rear;
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

template <typename T> 
bool Queue<T>::Empty() {
  Node<T>* front = this->front;
  if (front == NULL) return true;
  return false;
}

template <typename T>
T Queue<T>::Front() {
  return this->front->data;
}

#endif