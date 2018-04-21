#include <iostream>
using namespace std;
int main(){
    int a, b, up, down;
    while(cin >> a >> b && a != -1){
        if(a < b) {
            up = b - a;
            down = a + 100 - b;
        }else{
            up = a - b;
            down = b + 100 - a;
        }
        if(up < down) cout << up << endl;
        else cout << down << endl;
    }
}