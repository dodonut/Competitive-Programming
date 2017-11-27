#include <iostream>
int main(int argc, const char *argv[])
{
    std::string x;
    std::string bend;
    int n;
    while (std::cin >> n && n) {
        x = "+x";
        while (--n) {
            std::cin >> bend;
            if(bend != "No"){
                if(x == "+x") x= bend;
                else if(x == "-x"){
                    if(bend[0] == '-') x[0] = '+';
                    x[1] = bend[1];
                }
                else if(x[1] == bend[1]) {
                    if(x[0] == '+'){
                        if(bend[0]=='+') x = "-x";
                        else x = "+x";
                    }
                    else{
                        if(bend[0] == '+') x = "+x";
                        else x = "-x";
                    }
                }
            } 
        }
        std::cout << x << std::endl;
    }
    return 0;
}
