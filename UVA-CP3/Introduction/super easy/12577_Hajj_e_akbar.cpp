#include <iostream>
using namespace std;
int main(){
    int c = 1;
    string s;
    while(cin >> s && s != "*"){
        if (s == "Hajj") printf("Case %d: Hajj-e-Akbar\n",c++);
        else printf("Case %d: Hajj-e-Asghar\n",c++);
    }
}