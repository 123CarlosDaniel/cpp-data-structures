#include <iostream>

using namespace std;
// stack implementation with arrays
int A[101];
int top = -1;

void Push(int data) {
  if (top == 100) {
    cout<<"Error: stack overflow "<<endl;
    return;
  }
  A[++top] = data;
}

void Pop() {
  if (top == -1) {
    cout<<"Error: stack is empty, no elements to pop"<<endl;
    return;
  }
  top--;
}

int Top(){
  return A[top];
}

void Print() {
  cout<<"Data : ";
  for (int i{}; i<top+1;i++){
    cout<<A[i]<<" ";
  }
  cout<<endl;
}

int main() {
  Push(2);
  Print();
  Push(3);
  Print();
  Push(5);
  Print();
  Pop();
  Print();
  Push(12);
  Print();
}