#include <iostream>

using namespace std;

int MAX, at[21], def[21], hab[21];

bool prassodia(int a, int d, int h, int index, int cartas_juntadas){
    if(!(a && d && h) && cartas_juntadas > 1){
        return true;
    }
    for(int i = index; i < MAX; i++){
            int x = a - at[i];
            int y = d - def[i];
            int z = h - hab[i];
            if((x >= 0 && y >= 0 && z >= 0))
                return prassodia(x,y,z, i+1, cartas_juntadas + 1) || prassodia(a,d,h,i+1, cartas_juntadas);
    }
    return false;
}

int main(){
    int c, pr_at, pr_def, pr_hab;

    scanf("%d %d %d %d", &MAX, &pr_at, &pr_def, &pr_hab);

    for(int i = 0; i < MAX; i++){
        scanf("%d %d %d",&at[i], &def[i], &hab[i]);
        
    }
    if(prassodia(pr_at, pr_def, pr_hab,0,0))
        cout << "Y\n";
    else cout << "N\n";
    
}
