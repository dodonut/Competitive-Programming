#include <iostream>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    string s;
    while(tc--){
        cin >> s;
        if(s.size() == 1 || s.size() == 2){
            if(s == "1" || s == "4" || s == "78") cout << '+' << endl;
        }
        else if(s.find("35") == s.size()-2 || 
                s.find("5") == s.size()-1 || 
                s.find("3") == s.size()-2) cout << '-' << endl;
        else if(s[0] == '9' || s[s.size()-1] == '4') cout << '*' << endl;
        else if(s.find("190") == 0 || 
                s.find("1") == 0 ||
                s.find("9") == 1 ||
                s.find("0") == 2 ||
                s.find("90") == 2 ||
                s.find("19") == 1) cout << '?' << endl;
    }
}