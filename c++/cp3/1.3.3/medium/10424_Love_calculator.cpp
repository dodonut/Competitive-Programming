#include <iostream>
int main()
{
    std::string n1,n2;
    while(getline(std::cin, n1) && getline(std::cin, n2)){
        int t1=0,t2=0;
        
        for (int i = 0; i < n1.size(); i++) {
            if(n1[i] >= 65 && n1[i] <= 90 ) t1 += n1[i] - 'A'+1;
            else if (n1[i] >= 97 && n1[i] <= 122) t1 += n1[i] - 'a' + 1;
        }
        
        for (int i = 0; i < n2.size(); i++) {
            if(n2[i] >= 65 && n2[i] <= 90 ) t2 += n2[i] - 'A' + 1;
            else if (n2[i] >= 97 && n2[i] <= 122) t2 += n2[i] - 'a' + 1;
        }
        while(t1 > 9) {
            int aux=t1;
            t1 = 0;
            while (aux) {
                t1 += aux%10;
                aux = aux/10;
            }
        }
        while(t2 > 9) {
            int aux=t2;
            t2 = 0;
            while (aux) {
                t2 += aux%10;
                aux = aux/10;
            }
        }
        if((float)t2/t1 > 1){
            printf("%.2f \%\n",100*(float)t1/t2);
        }
        else 
            printf("%.2f \%\n",100* (float)t2/t1);
    }
    return 0;
}
