#include <cstdio>
#include <map>
#include <algorithm>

int main()
{
    int n, A[5], max, maxNumStudents;
    char s[20];
    std::string t;
    while (scanf("%d", &n) && n)
    {
        max = 0;
        maxNumStudents = 0;
        std::map<std::string, int> record;
        while (n--)
        {
            scanf("%d %d %d %d %d", &A[0], &A[1], &A[2], &A[3], &A[4]);
            std::sort(A, A + 5);
            sprintf(s, "%d%d%d%d%d", A[0], A[1], A[2], A[3], A[4]);
            t = s;
            record[t]++;
            if (record[t] > max)
                max = record[t];
        }
        for (auto &&v : record)
        {
            if (v.second == max)
                maxNumStudents += max;
        }
        printf("%d\n", maxNumStudents);
    }
    return 0;
}