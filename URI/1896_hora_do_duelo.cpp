#include <iostream>
#include <set>
using namespace std;

#define ii pair<int,int>
#define iii pair<int, ii>
int MAX, at[21], def[21], hab[21];
bool colocado[21] {0};

bool prassodia(iii falta, int index){
    if(make_pair(0,make_pair(0,0)) == falta){
        return true;
    }
    for(int i = index; i < MAX; i++){
            int a = falta.first - at[i];
            int d = falta.second.first - def[i];
            int h = falta.second.second - hab[i];
            if(a > 0 && d > 0 && h > 0)
            return prassodia(make_pair(a, make_pair(d,h)), i);
    }
    return false;
}

int main(){
    int c, pr_at, pr_def, pr_hab;

    scanf("%d%d%d%d", &MAX, &pr_at, &pr_def, &pr_hab);

    for(int i = 0; i < MAX; i++){
        scanf("%d%d%d",at[i], def[i],hab[i]);
        
    }
    if(prassodia(make_pair(pr_at, make_pair(pr_def, pr_hab)),0))
        cout << "Y\n";
    else cout << "N\n";
    
}
