#include <iostream>
#include <set>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m;
    uint32_t val, cont;
    while (scanf("%d %d", &n, &m), n || m)
    {
        std::set<uint32_t> cds;
        cont = 0;
        while (n--)
        {
            scanf("%u", &val);
            cds.insert(val);
        }
        while (m--)
        {
            scanf("%u", &val);
            if (cds.count(val))
                cont++;
        }
        printf("%u\n", cont);
    }
}