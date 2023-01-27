#include <iostream>
#include <string>
using namespace std;

class rectangle {
public: 
  float length, width;
  float area();
  bool squareCheck();
};

float rectangle::area() {
  return (length * width);
}

bool rectangle::squareCheck() {
  if (length == width) 
      return true;
  else  
    return false;
}

int main() {
  rectangle r1, r2;
  cout << "width of 1: ";
  cin >> r1.width;
  cout << "length of 1: ";
  cin >> r1.length;
  cout << endl;
  
  cout << "width of 2: ";
  cin >> r2.width;
  cout << "length of 2: ";
  cin >> r2.length;
  cout << endl;
  
  cout << "area of 1: " << r1.area() << endl;
  if (r1.squareCheck()) 
    cout << "1 is a square" << endl;
  else 
    cout << "1 is not a square" << endl;
  cout << endl;
  
  cout << "area of 2: " << r2.area() << endl;
  if (r2.squareCheck()) 
    cout << "2 is a square" << endl;
  else 
    cout << "2 is not a square" << endl;
  cout << endl;
  
  return 0;
}