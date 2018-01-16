#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const* argv[])
{
  int A, C, c;
  int counter, i;
  int vale, peak, Greatest, secGreat;
  while (cin >> A >> C, A) {
    int X[C+1] = {0};
    c = 0;
    while (c < C) cin >> X[c++];
    counter = 0;
    peak = X[0];
    secGreat = X[0];
    vale = X[0];
    Greatest = X[0];
    //too slow
    // for (int i = 1; i <= height; i++) {
    //   laserON = false;
    //   for (int j = 0; j < lenght; j++) {
    //     if (X[j] < i) {
    //       if (!laserON) {
    //         counter++;
    //         laserON = true;
    //       }
    //     }
    //     else {
    //       laserON = false;
    //     }
    //   }
    // }
    for (i = 1; i < C-1; i++) {
      if (X[i-1] <= X[i]) {
        peak = X[i];
        secGreat = Greatest;
        Greatest = max(peak, Greatest);
        if (X[i] > X[i+1]) {
          counter += peak - vale;
        }
      }
      else {
        vale = X[i];
      }
    }
    Greatest = max(X[C-1], Greatest);
    if(Greatest == A) counter++;
    //last one was a vale
    if(X[C-1] < X[C-2]) counter += peak - X[C-1];
    //last one was equal 
    else if(X[C-1] == X[C-2]) counter += peak - vale;
    //last one was greater
    else counter += X[C-1] - vale;
    counter += Greatest != X[0] ? A - Greatest : A - secGreat;
    cout << counter << endl;
  }
}
