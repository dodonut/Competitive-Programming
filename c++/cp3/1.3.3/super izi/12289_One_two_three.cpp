#include <iostream>
using namespace std;
int main(){
    int n, c1 = 0, c2 = 0;
    string vet[] = {"one","two","three"};
    string ans;
    cin >> n;
    while(n--){
        c1 = 0;
        c2 = 0;
        cin >> ans;
        if(ans.size() == vet[2].size()) printf("%d\n",3);
        else {
            for(int i = 0; i < vet[1].size(); i++){
                if(ans[i] == vet[0][i]) c1++;
                else if(ans[i] == vet[1][i]) c2++;
            }
            if (c1 > 1) printf("%d\n",1);
            else printf("%d\n",2);
        }
    }
}