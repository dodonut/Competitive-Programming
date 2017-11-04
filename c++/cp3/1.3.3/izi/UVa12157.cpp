#include <iostream>
using namespace std;
int main(){
    int tc, c=1;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        int calldur, mile = 0, juice = 0;
        while(n--){
            cin >> calldur;
            mile += ((calldur/30) + 1)*10;
            juice += ((calldur/60) + 1)*15;
        }
        printf("Case %d: ",c++);
        if (mile < juice)  printf("Mile %d\n",mile);
        else if(mile > juice) printf("Juice %d\n",juice);
        else printf("Mile Juice %d\n",mile);  
    }
}
