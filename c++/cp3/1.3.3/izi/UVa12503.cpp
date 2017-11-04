#include <iostream>
using namespace std;
int main(){
    int tc, c = 1;
    cin >> tc;
    while(tc--){
        int n,p = 0, a;
        c = 1;
        cin >> n;
        int vet[101]={0};
        string k;
        while(n--){
            cin >> k;
            if(k == "LEFT")vet[c++] = -1;
            else if(k == "RIGHT")vet[c++] = 1;
            else {
                cin >> k;
                cin >> a;
                vet[c++] = vet[a];
            }
        }
        for(int i = 1; i < 101; i++){
            p += vet[i];
        }
        cout << p << endl;
    }
}