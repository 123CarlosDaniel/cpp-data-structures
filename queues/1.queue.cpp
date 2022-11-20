#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
  Queue* queue = new Queue();
  queue->Print();
  queue->Enqueue(4);
  queue->Enqueue(4);
  queue->Dequeue();
  queue->Print();
  Queue queue2(2) ;
  queue2.Enqueue(456);
  queue2.Print();
}
