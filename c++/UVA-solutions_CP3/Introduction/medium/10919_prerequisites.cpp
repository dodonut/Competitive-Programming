#include <iostream>
#include <algorithm>
int main(int argc, const char *argv[])
{
    int k, m;
    while (std::cin >> k && k && std::cin >> m) {
        int k1 = k, m1 = m, c = 0;
        int courses[k1]={0},cat[m1]={0};
        while (k1--) {
            std::cin >> courses[c++];
        }
        int r, ca;
        int flag=0;
        while (m1--) {
            c = 0;
            std::cin >> ca >> r;
            int ca1 = ca;
            while (ca1--) {
                std::cin >> cat[c++];
            }
            int tot = 0;
            for(int i = 0; i < ca; i++){
                for(int j = 0; j < k; j++){
                    if(cat[i] == courses[j]) tot++;
                }
            }
            if(tot < r) flag = 1;
        }
        if(flag) std::cout << "no" << std::endl;
        else std::cout << "yes" << std::endl;
    }
    return 0;
}
