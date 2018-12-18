#include <iostream>
#include <queue>

int main()
{
    int t, val, tot_cost, result;
    while (scanf("%d", &t), t)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        while (t--)
        {
            scanf("%d", &val);
            q.push(val);
        }
        tot_cost = 0;
        result = 0;
        while (q.size() > 1)
        {
            result = q.top();
            q.pop();
            result += q.top();
            q.pop();

            tot_cost += result;
            q.push(result);
        }
        printf("%d\n", tot_cost);
    }
}