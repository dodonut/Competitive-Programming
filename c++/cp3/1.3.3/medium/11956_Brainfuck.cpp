#include <iostream>
using namespace std;
int main(int argc, char const* argv[])
{
  int T;
  int p;
  int c;
  string in;
  cin >> T;
  c = 1;
  while (T--) {
    int X[100] = {0};
    p = 0;
    cin >> in;
    for (char ch : in) {
      switch (ch) {
        // case '.':
        //          cout << ch << endl;
        //            break;
        case '+':
          X[p] = (X[p] + 1) % 256;
          break;
        case '-':
          X[p] = (X[p] - 1) < 0 ? 255 : X[p]-1;
          break;
        case '>':
          p = (p + 1) % 100 ;
          break;
        case '<':
          p = (p - 1) < 0 ? 99 : p - 1;
          break;
      }
    }
    printf("Case %d: ", c++);
    for (int i = 0; i < 100; i++) {
      if (i > 0) {
        cout << ' ';
      }
      printf("%.2X", X[i]);
    }
    cout << endl;
  }
  return 0;
}
