#include <iostream>
#include <string>
#include <map>
int main()
{
    int vert[4]{1, 2, 6, 5}, hor[4]{4, 6, 3, 1};
    int T, iv, ih;
    int *res = new int();
    char a[6];
    std::string word;
    while (scanf("%d", &T) && T)
    {
        iv = 0; ih = 0;
        while (T--)
        {
            scanf(" %s", &a);
            word = a;
            if (word == "north")
            {
                iv = (iv + 3) % 4;
                res = vert + iv;
            }
            else if (word == "south")
            {
                iv = (iv + 1) % 4;
                res = vert + iv;
            }
            else if (word == "west")
            {
                ih = (ih + 3) % 4;
                res = hor + ih;
            }
            else
            {
                ih = (ih + 1) % 4;
                res = hor + ih;
            }
        }
        printf("%d\n", *res);
    }
}