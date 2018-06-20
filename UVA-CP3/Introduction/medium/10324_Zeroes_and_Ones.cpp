#include <iostream>
int main(int argc, const char *argv[])
{
    std::string s;
    int i, j, n;
    int c = 1;
    while (std::cin >> s) {
        std::cin.ignore();
        std::cin >> n ;
        printf("Case %d:\n", c++);
        while(n--){
            int flag = 0;
            std::cin.ignore();
            std::cin >> i >> j;
            if (i == j) {
                flag = 0;
            }else if (i < j) {
                for (; i < j; i++) {
                    if(s[i] != s[i+1]) flag = 1;
                }
            }else {
                for (;j < i; j++) {
                    if(s[j] != s[j+1]) flag = 1;
                }
            }
            if (flag) std::cout << "No" << std::endl;
            else std::cout << "Yes" << std::endl;
        }
        std::cin.ignore();
    }
    return 0;
}
