#include <iostream>
using namespace std;
int main(){
    int start, n1,n2,n3,sum = 0 ;
    while(cin >> start >> n1 >> n2 >> n3 && (start || n1 || n2 || n3)){
        sum = 1080;
        sum += (start - n1 > 0) ? 9 * (start - n1) : 9 * (start + 40 - n1);
        sum += (n2 - n1 > 0) ? 9 * (n2 - n1) : 9 * (n2 + 40 - n1);
        sum += (n2 - n3 > 0) ? 9 * (n2 - n3) : 9 * (n2 + 40 - n3);
        cout << sum << endl;
    }
}