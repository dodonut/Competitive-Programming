#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    int cont = 0;
    vector<int> t(2);
    iota(t.begin(), t.end(), 1);

    printf("auto i:\n");
    cont = 0;
    for (auto i : t)
    {
        printf("\ti: %d ref i: %x", i, &i);
    }
    printf("\nauto& i:\n");
    cont = 0;
    for (auto &i : t)
    {
        printf("\ti: %d ref i: %x", i, &i);
    }
    printf("\ntauto&& i:\n");
    cont = 0;
    for (auto &i : t)
    {
        printf("\ti: %d ref i: %x", i, &i);
    }
    printf("\nref t[i]:\n");
    cont = 0;
    printf("t[i] %x", &t);
    printf("\n\n");
    return 0;
}