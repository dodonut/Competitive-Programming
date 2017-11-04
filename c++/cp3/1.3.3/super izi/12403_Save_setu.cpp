#include <iostream>
using namespace std;
int main(){
    int tc, val, sum = 0;
    string n;
    cin >> tc;
    while(tc--){
        cin >> n;
        if(n == "donate"){
            cin >> val;
            sum += val;
        }
        else cout << sum << endl;
    }
}