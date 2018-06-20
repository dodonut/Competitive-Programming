#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int tc, vet[3], c = 1;
    cin >> tc;
    while(tc--){
        cin >> vet[0] >> vet[1] >> vet[2];
        sort(vet, vet+3);
        printf("Case %d: %d\n", c++, vet[1]);
    }
}   