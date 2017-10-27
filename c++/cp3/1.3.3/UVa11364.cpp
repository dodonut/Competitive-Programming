#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int tc, ns, nscpy, sp, minDist = 0, min, c = 0, vet[105]={0};
    cin >> tc;
    while(tc--){
        minDist = 0;
        c = 0;
        cin >> ns;
        nscpy = ns;
        while (ns--){
            cin >> sp;
            vet[c++] = sp;
        }
        sort(vet, vet+nscpy);
        for(int i = nscpy -1; i > 0; i--) minDist += vet[i] - vet[i-1];
        cout << minDist * 2 << endl;
    }
}