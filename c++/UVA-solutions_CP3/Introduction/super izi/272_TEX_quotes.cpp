#include <iostream>
using namespace std;
int main(){
    string s, s2 = "";
    int cont = 0;
    while(getline(cin,s)){
        for(int i = 0; i < s.size(); i++){
            if (s[i] != '"'){
                s2 += s[i]; 
            }else if(cont == 0){
                s2 += "``"; cont++;
            }else {
                s2 += "\'\'"; cont = 0;
            }
        }
        s2 += '\n';
        
    }
    cout << s2;
}