#ifndef LINKED_H
#define LINKED_H

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
  ~Node(){
    cout<<"Deleting node "<<this<<endl;
  }
};

class LinkedList {
  private : 
    Node* head;
    int lenght{};
  public :
    LinkedList(){
      head = NULL;
    };
    LinkedList(int data) {
      head = new Node(data); 
    }
    ~LinkedList(){
      Node* tempHead = this->head; 
      while (tempHead != NULL)
      {
        Node* next = tempHead->next;
        delete tempHead;
        tempHead = next;   
      }
      cout<<"Deleting linkedlist"<<endl;
    }
    void Print();
    void Insert(int n, int data);
    void Push(int data);
    void Delete(int n);
    void Reverse();
};

#endif