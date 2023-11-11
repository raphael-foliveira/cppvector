#include "MyVector.hpp"
#include <iostream>
using namespace std;

int main() {
  MyVector<int> myVector;

  myVector.push(4);
  myVector.push(4);
  myVector.push(2);

  int* firstElementPtr = myVector.get(0);
  int* fifthElementPtr = myVector.get(4);

  cout << myVector.toString() << endl;
  if (firstElementPtr != nullptr) {
    cout << *myVector.get(0) << endl;

  }
  if (fifthElementPtr != nullptr) {
    cout << *myVector.get(4) << endl;
  }
}

