#include <iostream>
using namespace std;
int main(){
    int tc, c = 1;
    cin >> tc;
    while(tc--){
        int N, wall, nw, hj = 0, lj = 0;
        cin >> N;
        cin >> wall;
        N--;
        while(N--){
            cin >> nw;
            if (nw > wall) hj++;
            else if(nw < wall) lj++;
            wall = nw;
        }
        printf("Case %d: %d %d\n",c++, hj, lj);
    }
}