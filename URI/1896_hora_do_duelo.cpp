#include <iostream>

using namespace std;

int MAX, at[21], def[21], hab[21];
bool is_prassodia = false;

void prassodia(int a, int d, int h, int index, int cartas_juntadas){
    if(!is_prassodia){
        if(a == 0 && d == 0 && h == 0 && cartas_juntadas > 1){
            is_prassodia = true;
        }
        for(int i = index; i < MAX; i++){
            int x = a - at[i];
            int y = d - def[i];
            int z = h - hab[i];
            if(x >= 0 && y >= 0 && z >= 0)
                prassodia(x,y,z, i+1, cartas_juntadas + 1);
        }
    }
}

int main(){
    int c, pr_at, pr_def, pr_hab;

    scanf("%d %d %d %d", &MAX, &pr_at, &pr_def, &pr_hab);

    for(int i = 0; i <= MAX; i++){
        at[i] = def[i] = hab[i] = 0;
    }

    for(int i = 0; i < MAX; i++){
        scanf("%d %d %d",&at[i], &def[i], &hab[i]);
    }
    prassodia(pr_at, pr_def, pr_hab,0,0);
    if(is_prassodia)
        cout << "Y\n";
    else cout << "N\n";
    
}
