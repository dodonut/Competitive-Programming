#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    int L, mindist;    
    int count;
    string places;
    while(cin >> L, L){
      mindist = L;
      int lastr = -L, lastd = -L;
      int cur = 0;
      cin >> places;
      while (cur < L) {
        if(places[cur] == 'Z'){
          mindist = 0;
          break;
        }
        else if (places[cur] == 'R') {
          mindist = min(mindist, cur - lastd);
          lastr = cur;
        }
        else if (places[cur] == 'D') {
          mindist = min(mindist, cur - lastr);
          lastd = cur;
        }
        cur++;
      }
      cout << mindist << endl;
    } 
    return 0;
}
