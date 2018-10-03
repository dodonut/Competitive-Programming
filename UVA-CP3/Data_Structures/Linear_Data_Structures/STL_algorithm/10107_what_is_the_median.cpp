#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::vector<unsigned long int> v;
    while (scanf("%d", &n) != EOF)
    {
        v.insert(std::upper_bound(v.begin(), v.end(), n), n);
        if (v.size() % 2 == 0)
            printf("%d\n", (v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2);
        else
            printf("%d\n", v[v.size() / 2]);
    }
}