#include <iostream>
#include <map>

std::map<char, int> table;

int main()
{
    int n, k, val, sum;
    char c;
    scanf("%d", &n);
    while (n--)
    {
        sum = 0;
        table.clear();
        scanf("%d", &k);
        while (k--)
        {
            scanf(" %c %d", &c, &val);
            table[c] = val;
        }
        scanf("%d ", &k);
        while (k--)
        {
            while (scanf("%c", &c), c != '\n')
                sum += table[c];
        }
        printf("%d.%02d$\n", sum / 100, sum % 100);
    }
}