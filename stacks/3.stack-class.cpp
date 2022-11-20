#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;


int main() {
  int n, data;
  Stack<int> stack ;   
  stack.Print();
  cout<<"Enter the number of elements : ";
  cin>>n;  
  for(int i{}; i < n ; i++) {
    cout<<"Enter the data to push : ";
    cin>>data;
    stack.Push(data);
  }
  stack.Print();
  stack.Pop();
  stack.Print();
  Stack<string> stackString;
  stackString.Push("hola");
  stackString.Push("rata");
  stackString.Push("meeeeee");
  stackString.Print();
}