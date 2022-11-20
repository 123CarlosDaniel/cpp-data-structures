#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;

void ReverseWord( string& C) {
  int l = C.length();
  Stack<char> word;
  for ( int i {}; i < l ; i++) {
    word.Push(C[i]);
  }
  for (int i {}; i < l ; i++) {
    C[i] = word.Top();
    word.Pop();
  }
}

int main() {
  string word;
  cout<<"Enter the word : ";
  getline(cin, word);
  cout<<word.length()<<endl;
  cout<<"Word normal order : "<<word<<endl;
  ReverseWord(word);
  cout<<"Word in reverse order : "<<word<<endl;
}