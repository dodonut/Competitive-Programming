#include <iostream>
using namespace std;
int main(){
    int tc, vet[11], ordup, orddown;
    cin >> tc;
    cout << "Lumberjacks:\n";
    while(tc--){
        ordup = 0;
        orddown = 0;
        for (int i = 0; i < 10; i++){
            cin >> vet[i];
        }
        for (int i = 0; i < 9; i++){
            if (vet[i] > vet[i+1]) orddown++;
            else ordup++;
        } 
        if (ordup == 9 || orddown == 9) cout << "Ordered\n";
        else cout << "Unordered\n";

    }
}