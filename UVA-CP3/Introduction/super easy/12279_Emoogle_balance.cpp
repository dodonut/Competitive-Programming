#include <iostream>
using namespace std;
int main(){
    int n, nt, t, k, c = 1;
    while(cin >> n && n != 0){
        t = 0;
        nt = 0;
        while(n--){
            cin >> k;
            if(k != 0) nt++;
            else t++;
        }
        printf("Case %d: %d\n",c++, nt-t);
        
    }
}