#include <iostream>
using namespace std;
int main(){
    int n,c=1,singed = 0,hmt;
    string b["Happy","birthday","to","you","Rujia"];
    cin >> n;
    string s[n+1];
    while(n--)cin >> s[c++];
    if (n/16 > 0) hmt = (n/16 +1)*2;
    else hmt = n;
    for (int i = 0; i < hmt; i++){
        cout << s[i%n] << ": ";
        if (singed == 3) cout << vet[4] << endl;
        else cout << vet[3] << endl;
    }

}