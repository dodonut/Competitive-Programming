#include <iostream>
#include <algorithm>

int main()
{
    std::string a;
    int i;
    while (std::cin >> a && a != "#")
    {
        if(std::next_permutation(a.begin(), a.end()))
            printf("%s\n",a.c_str());
        else printf("No Successor\n");
    }
}