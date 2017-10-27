#include <iostream>
using namespace std;
int main(){
    int cont = 1;
    string s;
    while(cin >> s && s != "#"){
        printf("Case %d: ",cont++);
        if (s == "HELLO") printf("%s","ENGLISH\n");
        else if (s == "HOLA") printf("%s","SPANISH\n");
        else if (s == "HALLO") printf("%s","GERMAN\n");
        else if (s == "BONJOUR") printf("%s","FRENCH\n");
        else if (s == "CIAO") printf("%s","ITALIAN\n");
        else if (s == "ZDRAVSTVUJTE") printf("%s","RUSSIAN\n");
        else printf("%s","UNKNOWN\n");
    }
}