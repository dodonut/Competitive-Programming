#include <iostream>
int main(int argc, char const* argv[])
{
  int A, C, c;
  int height, lenght;
  int n, nbef;
  while (cin >> A >> C, A) {
    int X[C] = {0};
    c = 0;
    height = A;
    lenght = C;
    while (lenght--) {
      cin >> X[c++];
    }

    lenght = C;
    n = 0;
    int c = 1;
    bool allLineIsLess = true;
    while (height-- && n != nbef) {
      nbef = n;
      while (c < lenght) {
         if (X[c] >= height) {
           n++;
           allLineIsLess = false;
         } 
         c++;
      }
      c = 0;
      if(allLineIsLess) n++;
    }
    cout << n << endl;
  }
}
