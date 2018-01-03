#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    int L, mindist;    
    int count;
    string places;
    while(cin >> L){
        cin >> places;
        int fromStart = 0;
        int fromEnd = L - 1;
        count = 0;
        mindist = 9999999;
        while(fromStart++ != L){
            if(places[fromStart] == 'R'){
                while(places[fromStart++] != 'D'){
                    count++;
                    if(places[fromStart] == 'R'){
                        count = 0;
                    }
                    else {
                        mindist = 0;
                        break;
                    }
                }  

                if(places[fromStart] == 'D') {
                    if(count < mindist) mindist = count;
                }
                else break;
            }
        }
        printf("min %d\n", mindist);
    } 
    return 0;
}
