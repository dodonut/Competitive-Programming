#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    int L, mindist;    
    int beforerest, afterrest;
    string places;
    while(cin >> L){
        cin >> places;
        int cont = 0;
        beforerest = 0;
        afterrest = 0;
        mindist = 9999999;
        while(cont++ != L){
            if(places[cont] == 'Z'){
                mindist = 0;
                break;
            }
            else if(places[cont] != 'R'){

            }
        cout << mindist << endl;
        }
    } 
    return 0;
}
