#include <iostream>
#include <vector>

int main()
{
    int N, count, bigger, sum_spaces;
    char c;
    std::vector<int> qtd_x;
    while (scanf("%d", &N), N)
    {
        qtd_x.clear();
        bigger = 0;
        sum_spaces = 0;
        while (N--)
        {
            count = 0;
            while (scanf("%c", &c))
            {
                if (c == 'X')
                    count++;
                else if (c == '\n')
                    break;
            }
            bigger = std::max(count, bigger);
            qtd_x.push_back(count);
        }
        for (auto &i : qtd_x)
            sum_spaces += bigger - i;
        printf("%d\n", sum_spaces);
    }
}