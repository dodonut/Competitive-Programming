#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;
int main(){
    //THE NUMBER OF CASES GIVEN AT FIRST LINE OF INPUT
    /*
    int TC, a, b;
    cin >> TC;
    while (TC--){
        cin >> a >> b;
        cout << a + b << endl;
    }
    */

    //THE INPUT ENDS WHEN BOTH NUMBERS ARE 0
    /*
    int a,b;
    while(cin >> a >> b, (a || b)) cout << a + b << endl;
    //or
    //while(cin >> a >> b && (a || b)) cout << a + b << endl;    
    */


    //THE INPUT ENDS WHEN THE FILE ENDS
    /*int a,b;
    while(cin >> a >> b) cout << a + b << endl;
    */

    //PRINTING CASE [NUMBER]: [ANSWER]
    /*PROBLEM, HAS AN EXTRA JUMP OF LINE AT THE END
    int a,b, c = 1;
    while(cin >> a >> b)  printf("Case %d: %d\n\n", c++, a+b);
    */

    //FIX ABOVES PROBLEM
    /*
    int a,b, c = 1;
    while(cin >> a >> b){
        if (c > 1) cout << endl;
        printf("Case %d: %d\n", c++, a+b);
    }
    */
    
    //SUM N INTEGERS ON THE LINE
    /*
    int n, b, c;
    while( cin >> n){
        b = 0;
        while(n-- && cin >> c) b += c;
        printf ("%d\n",b);
    }
    */

    //SUM WITHOUT THE N TO TELL HOW MANY INTEGERS HAVE TO SUM
    //???

        
}