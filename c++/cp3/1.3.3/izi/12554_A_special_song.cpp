#include <iostream>
using namespace std;
int main(){
    int n,c=0,singed = 0,hmt;
    string b[] = {"Happy","birthday","to","you","Rujia"};
    cin >> n;
    string s[n+1];
    int np = n;
    int when = 11;
    while(n--)cin >> s[c++];
    if (np/16 > 0) hmt = (np/16 + 1)*16;
    else hmt = 16;
    for (int i = 0; i < hmt; i++){
        cout << s[i%np] << ": " ;
        if(i == when){
            cout << "Rujia" << endl;
            when += 16;
        }
        else cout << b[i%4] << endl;
    }
}