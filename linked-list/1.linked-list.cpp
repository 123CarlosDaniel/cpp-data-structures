#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};
void insert(Node** head, int val){
  Node* temp = new Node();
  temp->data = val;
  temp->next = NULL;
  if (*head != NULL) temp->next = *head;
  *head = temp;
};

void Print(Node* head) {
  cout<<"List is: ";
  while (head != NULL)
  {
    cout<<" "<<head->data;
    head= head->next;
  }
  cout<<endl;
};

int main() {
  Node* head = NULL;
  cout<<"How many numbers? \n";
  int n, i ,x;
  cin>>n;
  for (i = 0;i<n;i++) {
    cout<<"Enter the number \n";
    cin>>x;
    insert(&head,x);
    Print(head); 
  }
}
