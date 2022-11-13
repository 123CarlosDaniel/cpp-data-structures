#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};


void Print(Node* head) {
  cout<<"data : ";
  while(head != NULL) {
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

void Insert(Node** head, int n, int data) {
  Node* temp1 = new Node();
  temp1->data = data;
  temp1->next = NULL;

  if (n == 1) {
    temp1->next = *head;
    *head = temp1;
    return;    
  }
  Node* temp2 = *head;
  for (int i{};i<n-2;i++) {
    temp2 = temp2->next;  // searching for the (n-1) node 
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void Delete(Node** head, int n) {
  Node* temp1 = *head;
  if(n == 1) {
    *head = temp1->next;
    delete temp1;
    return;
  }
  for(int i = 0; i<n-2; i++){
    temp1 = temp1->next; // Node before the node to be deleted
  }
  Node* temp2 = temp1->next; // Node to be deleted
  temp1->next = temp2->next;
  delete temp2; 
}

int main(){
  Node* head = NULL;
  Insert(&head, 1, 2);
  Insert(&head,2,5);
  Insert(&head,3,8);
  Print(head);
  Delete(&head,2); // 2 8 
  Print(head);
}