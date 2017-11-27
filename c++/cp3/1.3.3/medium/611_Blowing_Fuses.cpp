#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    int n,m,c, total = 0,maximal = 0, seq = 1;
    while(cin >> n >> m >> c && n){
        int n1 = n;
        int n2;
        int flag = 0;
        int N[21]={0}, turn[21]={0};
        int k = 1;
        total = 0;
        maximal = 0;
        while(n1--){
            cin >> n2;
            N[k++] = n2;
        }
        int m1 = m;
        int m2;
        while(m1--){
            cin >> m2;
            if (turn[m2] == 0) {
                turn[m2] = 1;
                total += N[m2];
                if(total > c) flag = 1;
            }else{
                turn[m2] = 0;
                total -= N[m2];
            }
            if(total > maximal) maximal = total;
        }
        printf("Sequence %d\n", seq++);
        if (flag) {
            printf("Fuse was blown.\n");    
        }else {
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",maximal);            
        }
        std::cout << std::endl;

    }
    return 0;
}
