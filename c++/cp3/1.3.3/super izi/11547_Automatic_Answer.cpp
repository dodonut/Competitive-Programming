#include <iostream>
using namespace std;
int main(){
    int tc;long long n;
    cin >> tc;
    while(tc--){
        cin >> n;
        n = ((n*567/9) + 7492 )* 235 /47 - 498;
        cout << (abs(n) % 100 - (abs(n) % 10)) / 10<< endl;
    }
}