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
  for (int i{}; i<n-2;i++) { // iterating n-1 times
    temp1 = temp1->next;
  }
  Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  delete temp2;
}

void Reverse(Node** head) {
  
}

int main() {
  int n, num, position;
  Node* head = NULL;
  cout<<"How many numbers? : ";
  cin>> n;
  for (int i{};i <n;i++) {
    cout<<"Insert number : ";
    cin>>num;
    cout<<"At position : ";
    cin>>position;
    Insert(&head, position , num);
    Print(head);
  }
  cout<<"Do you want to delete a element? : ";
  cin>>position;
  Delete(&head, position);
  Print(head);
}