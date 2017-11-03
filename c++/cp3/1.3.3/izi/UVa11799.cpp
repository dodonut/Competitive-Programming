#include <iostream>
using namespace std;
int main(){
    int tc, c= 1;
    cin >> tc;
    while(tc--){
        int nc, hs = -1, cs;
        cin >> nc;
        while(nc--){
            cin >> cs;
            if (cs > hs) hs = cs;
        }
        printf("Case %d: %d\n", c++, hs);
    }
}