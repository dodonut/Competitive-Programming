#include <iostream>
#include <cstdio>
#include <bitset>

const int N = 1000005;
int z = 0;
std::bitset<N> calendar;
bool Conflict(int i, int f, int r)
{
    if (r > 0)
    {
        int k;
        do
        {
            for (k = i; k < f; k++)
            {
                if (!calendar.test(k))
                    calendar.set(k);
                else
                    return true;
            }
            i += r;
            f = (f + r > N) ? N : f + r;
        } while (i <= f);
        return false;
    }
    else
    {
        for (int k = i; k < f; k++)
        {
            if (!calendar[k])
            {
                calendar.set(k);
            }
            else
                return true;
        }
        return false;
    }
}

int main()
{
    int n, m, i, f, r;
    bool conflict;
    while (scanf("%d %d", &n, &m), (n || m))
    {
        conflict = false;
        calendar.reset();
        while (n--)
        {
            if (!conflict)
            {
                scanf("%d %d", &i, &f);
                conflict = Conflict(i, f, 0);
            }
            else
                scanf("%*d %*d");
        }
        while (m--)
        {
            if (!conflict)
            {
                scanf("%d %d %d", &i, &f, &r);
                conflict = Conflict(i, f, r);
            }
            else
                scanf("%*d %*d %*d");
        }
        if (!conflict)
            printf("NO ");
        printf("CONFLICT\n");
        z++;
    }
}