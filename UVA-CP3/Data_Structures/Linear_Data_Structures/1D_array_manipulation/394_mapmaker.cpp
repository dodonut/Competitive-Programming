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
        Arr.d_pairs.clear();
        Arr.C.clear();
        scanf(" %s %d %d %d", &Arr.name, &Arr.size, &Arr.D);
        for (int i = 0; i < Arr.D; i++)
        {
            scanf("%d %d", &L, &U);
            Arr.d_pairs.push_back(std::make_pair(L, U));
        }
        n[Arr.name] = Arr;
    }
    while (R--)
    {
        scanf(" %s", name);
        dimensions_of_name = n[name].D;
        for (int i = 0; i < dimensions_of_name; i++)
        {
            scanf("%d", &dim);
            //todo ler todas as dimensoes e colocar no vetor i, depois realizar o calculo seguindo a formula
            //de tras pra frente e armazenar em c
        }
    }
}