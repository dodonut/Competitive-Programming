#include <iostream>
#include <string>
#include <map>
int main()
{
    std::map<std::string, int> vet, vetaux;
    vetaux = vet;
    int T;
    char a[6];
    std::string word;
    while (scanf("%d", &T) && T)
    {
        vet["top"] = 1;
        vet["bottom"] = 6;
        vet["left"] = 3;
        vet["right"] = 4;
        vet["up"] = 2;
        vet["down"] = 5;
        while (T--)
        {
            vetaux = vet;
            scanf(" %s", &a);
            word = a;
            if (word == "north")
            {
                vet["top"] = vetaux["down"];
                vet["up"] = vetaux["top"];
                vet["bottom"] = vetaux["up"];
                vet["down"] = vetaux["bottom"];
            }
            else if (word == "south")
            {
                vet["top"] = vetaux["up"];
                vet["up"] = vetaux["bottom"];
                vet["bottom"] = vetaux["down"];
                vet["down"] = vetaux["top"];
            }
            else if (word == "west")
            {
                vet["left"] = vetaux["top"];
                vet["top"] = vetaux["right"];
                vet["right"] = vetaux["bottom"];
                vet["bottom"] = vetaux["left"];
            }
            else
            {
                vet["left"] = vetaux["bottom"];
                vet["top"] = vetaux["left"];
                vet["right"] = vetaux["top"];
                vet["bottom"] = vetaux["right"];
            }
        }
        printf("%d\n", vet["top"]);
    }
}