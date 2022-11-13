#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
  int n, data, ind;
  LinkedList* list = new LinkedList();
  list->Print();
  cout<<"Enter the number of elements : ";
  cin>>n;
  for (int i{1};i<n+1;i++) {
    cout<<"Enter the number to insert at "<<i<<" : ";
    cin>>data;
    list->Insert(i,data);
    list->Print();
  }
  cout<<"Enter the index of the number to delte : ";
  cin>>ind;
  list->Delete(ind);
  list->Print();
}