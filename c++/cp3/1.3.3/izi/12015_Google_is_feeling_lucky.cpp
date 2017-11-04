#include <iostream>
using namespace std;
int main(){
    int tc, c=1;
    string s[11];
    int rank[11], maior = -1;
    cin >> tc;
    while(tc--){
        maior = -1;
        for(int i = 0; i < 10; i++){
            cin >> s[i] >> rank[i];
            if(rank[i] > maior) maior = rank[i];
        }
        printf("Case #%d:\n",c++);
        for (int i = 0; i < 10; i++){
            if (rank[i] == maior)
                cout << s[i] << endl;
        }
    }
}