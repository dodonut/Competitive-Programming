#include <iostream>
#include <map>
#include <vector>

struct Array
{
    char name[11];
    int base, size, D;
    std::vector<std::pair<int, int>> d_pairs;
    std::vector<int> C;
};

int main()
{
    int N, R, L, U, dimensions_of_name, dim;
    char name[11];
    std::vector<int> I;
    std::map<std::string, Array> n;
    scanf("%d %d", &N, &R);

    Array Arr;
    while (N--)
    {
        scanf(" %s %d %d %d", &(Arr.name), &(Arr.base), &(Arr.size), &(Arr.D));
        for (int i = 0; i < Arr.D; i++)
        {
            scanf("%d %d", &L, &U);
            Arr.d_pairs.push_back(std::make_pair(L, U));
        }
        n[Arr.name] = Arr;
    }
    int Cd, Ld, Ud, C0, tot;
    while (R--)
    {
        n[name].C.clear();
        I.clear();

        scanf(" %s", name);
        dimensions_of_name = n[name].D;
        C0 = n[name].base;
        n[name].C.push_back(n[name].size);
        for (int i = 0; i < dimensions_of_name; i++)
        {
            scanf("%d", &dim);
            I.push_back(dim);

            Cd = n[name].C[i];
            Ld = n[name].d_pairs[dimensions_of_name - i - 1].first;
            Ud = n[name].d_pairs[dimensions_of_name - i - 1].second;
            C0 -= Cd * Ld;
            if (i < dimensions_of_name - 1)
                n[name].C.push_back(Cd * (Ud - Ld + 1));
        }

        tot = C0;
        for (int i = 0; i < dimensions_of_name; i++)
        {
            tot += n[name].C[dimensions_of_name - i - 1] * I[i];
        }
        printf("%s[%d", name, I[0]);
        for (int i = 1; i < dimensions_of_name; i++)
        {
            printf(", %d", I[i]);
        }
        printf("] = %d\n", tot);
    }
}