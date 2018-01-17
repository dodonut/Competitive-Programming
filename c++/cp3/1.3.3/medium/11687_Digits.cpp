#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const* argv[])
{
  string x0;
  int i;
  int xnext, xlast;
  while (cin >> x0 && x0 != "END") {
    xnext = x0.size();
    xlast = -1;
    i = 1;
    if(x0 != "1"){
      while (xnext != xlast) {
        xlast = xnext;
        x0 = std::to_string(xnext);
        xnext = x0.size();
        i++;
      }
    }
    cout << i << endl;
  }
  return 0;
}
