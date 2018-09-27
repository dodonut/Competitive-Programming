#include <iostream>
#include <vector>
#define vc std::vector<char>
#define vvc std::vector<vc>

bool matching(int N, int n, const vcc &small, const vcc &big, int big_row, int big_col)
{
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < n; l++)
        {
            if (big[big_row + k][big_col + l] != small[k][l])
                return false;
        }
    }
    return true;
}

int matchMatrix(int N, int n, const vvc &big, const vvc &small)
{
    int match = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matching(N, n, small, big, i, j))
                match++;
        }
    }
    return match;
}

void rotate(vvc &small, int n)
{
    vvc tmp(small);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            small[n - j - 1][i] = tmp[i][j];
}

int main()
{
    int N, n;
    vvc big_tb, small_tb;

    while (scanf("%d%d", &N, &n), N || n)
    {
        big_tb.resize(N, vc(N));
        small_tb.resize(N, vc(N));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf(" %c", &big_tb[i][j]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf(" %c", &small_tb[i][j]);

        for (int i = 0; i < 4; i++)
        {
            if (i)
                printf(" ");
            int matches = matchMatrix(N, n, big_tb, small_tb);
            printf("%d", matches);
            rotate(small_tb, n);
        }
    }
}