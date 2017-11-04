#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n, i = 1;
    while(cin >> n && n!=-1){
        printf("Teste %d\n%.f\n\n",i++, pow(pow(2,n)+1,2));
    }
}