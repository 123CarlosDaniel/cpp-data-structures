#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

void Print(Node* head) {
  cout<<"Data : ";
  while (head != NULL)
  {
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

void Insert(Node** head, int n ,int data){
  Node* temp1 = new Node();
  temp1->data = data;
  temp1->next = NULL;
  if (n == 1) {
    temp1->next = *head;
    *head = temp1;
    return;
  }
  Node* temp2 = *head;
  for(int i {}; i< n-2;i++) { //finding node before the node to insert
    temp2 = temp2->next; 
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void Delete(Node** head, int n) {
  Node* temp1 = *head;
  if (n == 1 ) {
    *head = temp1->next;
    delete temp1;
    return;
  }
  for (int i{}; i<n-2;i++) { // iterating n-1 times
    temp1 = temp1->next;
  }
  Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  delete temp2;
}

void Reverse(Node** head) {
  Node* prev = NULL;
  Node* current = *head;
  while (current != NULL)
  {
    Node* next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev; 
}

void _RecursiveReverse(Node* headNode, Node** head) {
  if (headNode->next == NULL) {
    *head = headNode;
    return;
  }
  _RecursiveReverse(headNode->next, head);
  Node* next = headNode->next;
  next->next = headNode;
  headNode->next = NULL;
}

void RecursiveReverse(Node** head) {
  Node* headNode = *head;
  _RecursiveReverse(headNode, head);
}

void RecursiveReverse2(Node** headPointer, Node* head, Node* prev = NULL) {
  if (head == NULL) {
    *headPointer = prev;
    return;
  }
  Node* next = head->next;
  head->next = prev; 
  RecursiveReverse2(headPointer, next, head);
}


int main() {
  int n, num, position;
  Node* head = NULL;
  cout<<"How many numbers? : ";
  cin>> n;
  for (int i{};i <n;i++) {
    cout<<"Insert number : ";
    cin>>num;
    Insert(&head, i+1 , num);
    Print(head);
  }
  // cout<<"Do you want to delete a element? : ";
  // cin>>position;
  // Delete(&head, position);
  Print(head);
  // Reverse(&head);
  // Print(head);
  // RecursiveReverse(&head);
  // Print(head);
  RecursiveReverse2(&head,head);
  Print(head);
}