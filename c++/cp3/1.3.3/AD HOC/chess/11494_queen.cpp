#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int a, b, c, d, here, going;
  while (cin >> a >> b >> c >> d, a || b || c || d)
  {
    here = abs(a - c);
    going = abs(b - d);
    if (a == c && b == d)
      cout << 0 << endl;
    else if (a == c || b == d)
      cout << 1 << endl;
    else if (here == going)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}