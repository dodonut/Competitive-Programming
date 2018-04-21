#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    int n, p, r, rbest = 0;
    float d, dbest = 0;
    int c = 1;
    string mat, companyname, theirmat;
    string tohire;
    while (cin >> n >> p && n) {
        if(c > 1) cout << endl;
        rbest = 0;
        dbest = 0;
        int n1 = n;
        cin.ignore();
        while (n1--) {
            getline(cin, mat);
        }
        int p1 = p;
        while(p1--){
            getline(cin, companyname);
            cin.ignore();
            cin >> d >> r;
            int r1= r;
            cin.ignore();
            while (r1--) {
                getline(cin, theirmat);
            }
            if (r > rbest) {
                 tohire = companyname;
                 rbest = r;
                 dbest = d;
            } 
            else if (r == rbest) {
                if (d < dbest) {
                     tohire = companyname;
                     rbest = r;
                     dbest = d;
                }
            }
        
        }
        printf("RFP #%d\n", c++);
        cout << tohire << endl;
    }   
    return 0;
}
