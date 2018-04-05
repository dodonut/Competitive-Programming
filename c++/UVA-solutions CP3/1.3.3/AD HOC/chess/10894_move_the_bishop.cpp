#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int T, t, N, a, b, c, d, here, going;
  cin >> T;
  while(T--){
    cin >> t >> N;
    while(t--){
      cin >> a >> b >> c >> d;
      here = abs(a - c);
      going = abs(b - d);
      if(a == c && b == d)
        cout << 0 << endl;
      else if(here == going)
        cout << 1 << endl;
      else if((here % 2 == 0 && going % 2 == 0) || (here %2 == 1 && going %2 ==1))
        cout << 2 << endl;
      else
        cout << "no move" << endl;
    }
  }
}