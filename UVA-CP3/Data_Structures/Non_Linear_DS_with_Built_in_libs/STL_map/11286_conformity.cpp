#include <cstdio>
#include <map>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T, course, s, tot;
    while (scanf("%d", &T), T)
    {
        std::map<int, int> frosh;
        while (T--)
        {
            s = 5;
            tot = 0;
            while (s--)
            {
                scanf("%d", &course);
                tot += course;
            }
            frosh[tot]++;
        }
        int more = 0;
        for (auto &&v : frosh)
        {
            if (v.second > more)
                more = v.second;
        }
        printf("%d\n", more);
    }
}