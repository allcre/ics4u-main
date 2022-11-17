#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

//Q1
int rec_a(int a) {
    if (a == 1)
        return 3;
    else 
        return (rec_a(a - 1) - 2);
}

int rec_b(int a) {
    if (a == 1)
        return -1;
    else
        return 2 * rec_b(a - 1);
}

//Q2
int gcd(int x, int y) {
    if (y == 0)
        return x;
    else 
        return gcd(y, x % y);
}

//Q3
string reverse(string sentence, string rev, int a) {
    if (a == 0)
        return (rev + sentence[a]);
    else {
        rev += sentence[a];
        return reverse(sentence, rev, a - 1);
    }
}

bool isPalindrome(string sentence, int a) {
    if (a <= 0) {
        if (sentence[0] == sentence[sentence.length() - 1])
            return true;
        else 
            return false;
    }
    else {
        if (sentence[a] == sentence[sentence.length() - 1 - a])
            return isPalindrome(sentence, a - 1);
        else 
            return false;
    }
}

//Q4
string decimalToBinary(int n, string x) {
     if (n == 0) {
        if (x.empty())
            return "0";
        else 
            return x;
     }
     else {
        x = to_string(n % 2) + x;
        n = floor(n / 2);
        return decimalToBinary(n, x);
     }
}

//Q5
long double average(int a[], int i) {
    if (i == 1) 
        return a[i - 1];
    else
        return (average(a, i - 1) * (i - 1) + a[i - 1]) / i;
}

//Q6
// initializes an array with whole numbers 1 through N
int init(int a[], int n) {
    if (n == 0)
        a[0] = 1; 
    else
        a[n] = 1 + init(a, n - 1);
    
    return a[n];
}

// find greatest common denominator
long gcd1(long x, long y) {
    if (y == 0)
        return x;
    else 
        return gcd(y, x % y);
}

// the lcm of 2 numbers is x*y / gcd(x,y), find fractorial from lcm of all numbers 1 - N
long fractorial(int a[], int i) {
    if (i == 0)
        return a[0];
    else {
        long x = a[i];
        long y = fractorial(a, i - 1);
        return (x * y / gcd1(x, y));
    }
}

int main() {
  //Q1
  cout << "term #: ";
  int n;
  cin >> n;
  cout << rec_a(n) << endl;
  cout << rec_b(n) << endl;

  //Q2
  cout << "find gcd of: ";
  int x, y;
  cin >> x >> y;
  cout << gcd(x, y) << endl;

  //Q3
  cout << "sentence: ";
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  string sentence;
  getline(cin, sentence);
  string rev = reverse(sentence, "", sentence.length() - 1);
  cout << rev << endl;

  // remove whitespace
  sentence.erase(remove_if(sentence.begin(), sentence.end(), ::isspace), sentence.end()); 
  // convert to lowercase
  for (int i = 0; i < sentence.length(); i++)
      sentence[i] = tolower(sentence[i]);
  
  if (isPalindrome(sentence, ceil(sentence.length()/2) - 1) == 1)
      cout << "true" << endl;
  else
      cout << "false" << endl;

  //Q4
  cout << "to binary: ";
  int p;
  cin >> p;
  string q;
  cout << decimalToBinary(p, q) << endl;

  //Q5
  cout << "array length: ";
  int r;
  cin >> r;
  int a[r];
  cout << "elements: ";
  for (int i = 0; i < n; i++)
      cin >> a[i];
  
  cout << setprecision(1) << fixed << average(a, r) << endl;

  //Q6
  cout << "fractorial: ";
  int s;
  cin >> s;
  int t[s];

  init(t, s);

  int size = sizeof(t)/sizeof(t[0]);
  cout << fractorial(t, size - 1) << endl;

  return 0;
}