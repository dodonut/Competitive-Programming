#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    int L, mindist;    
    int fs, fe;
    string places;
    while(cin >> L){
        int size = L;
        cin >> places;
        int fromStart = 0;
        int fromEnd = L - 1;
        bool foundR = false;
        bool foundD = false;
        fs = 0;
        fe = 0;
        mindist = 9999999;
        while(size--){
            if(places[fromStart] == 'Z'){
                mindist = 0;
                break;
            }
            if (places[fromEnd] == 'Z') {
                mindist = 0;
                break;
            }
            if(places[fromStart] == 'R'){
                fs = 0;
                foundR = true;
            }
            if(places[fromStart] == 'D' && foundR){
                if(fs < mindist) {
                    mindist = fs;
                    fs = 0;
                }
            }
            
            if(places[fromEnd] == 'D'){
                fe = 0;
                foundD = true;
            }
            if(places[fromEnd] == 'R' && foundD){
                if(fe < mindist) {
                    mindist = fe;
                    fe = 0;
                }
            }
            fs++;
            fe++;
            fromStart++;
            fromEnd--;
           
        }
        if(L)
            printf("min %d\n", mindist);
    } 
    return 0;
}
