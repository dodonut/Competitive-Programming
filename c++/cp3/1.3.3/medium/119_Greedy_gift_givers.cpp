#include <iostream>
using namespace std;
int main(){
    int np, c = 0;
    while(cin >> np){
        c = 0;
        int money[np]={0};
        int NP = np;
        string people[np];
        while(np--) cin >> people[c++];
        np = NP;
        while(np--){
            string giver;
            cin >> giver;
            int amountMoneyToGive;
            cin >> amountMoneyToGive;
            int numberpeoplegiven;
            cin >> numberpeoplegiven;
            int moneyspent;
            if (numberpeoplegiven == 0) moneyspent = 0;
            else moneyspent = amountMoneyToGive % numberpeoplegiven - amountMoneyToGive;
            for(int i = 0; i < NP; i++){
                if (people[i] == giver){
                    money[i] += moneyspent;
                    cout << "giver " << giver << '\t' << money[i] << endl;
                }
            }
            string peoplegiven[numberpeoplegiven];
            c = 0;
            int npg = numberpeoplegiven;
            while(npg--) {
                cin >> peoplegiven[c++];
            }
            for(int i = 0; i < numberpeoplegiven; i++){
                for(int j = 0; j < NP; j++){
                    if(peoplegiven[i] == people[j]){
                        money[j] += amountMoneyToGive/numberpeoplegiven;
                        //cout << peoplegiven[i] << '\t' << money[j] << endl;
                    }
                }
            }
        }
        for(int i = 0; i < NP; i++){
            cout << people[i] << " " << money[i] << endl;
        }
        cout << endl;
    }
}