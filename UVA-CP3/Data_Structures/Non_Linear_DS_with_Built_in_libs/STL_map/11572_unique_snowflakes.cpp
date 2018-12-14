#include <cstdio>
#include <set>
#include <vector>
// I'm a very good programmer
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t, n, val;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        std::vector<int> machine;
        std::set<int> record;
        while (n--)
        {
            scanf("%d", &val);
            machine.push_back(val);
        }

        int prev = 0, next = 0, max = 0;
        while (next < machine.size())
        {
            if (!record.count(machine[next]))
            {
                record.insert(machine[next]);
            }
            else
            {
                while (machine[prev] != machine[next])
                {
                    record.erase(machine[prev]);
                    prev++;
                }
                prev++;
            }
            next++;
            max = std::max(max, next - prev);
        }
        printf("%d\n", max);
    }
}