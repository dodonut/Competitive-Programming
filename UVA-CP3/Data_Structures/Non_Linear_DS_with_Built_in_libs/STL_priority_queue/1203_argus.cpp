#include <iostream>
#include <queue>

struct Register
{
    int num, period, original;
    Register(int n, int p) : num(n), period(p), original(p) {}
    bool operator<(const Register &r) const
    {
        if (period == r.period)
            return num > r.num;
        return period > r.period;
    }
};

int main()
{
    char s[10];
    int q_num, q_period, K;

    std::priority_queue<Register> queue;
    while (scanf("%s", s), s[0] != '#')
    {
        scanf("%d %d", &q_num, &q_period);
        queue.push(Register(q_num, q_period));
    }

    scanf("%d", &K);
    while (K--)
    {
        auto tmp = queue.top();
        printf("%d\n", tmp.num);
        queue.pop();
        tmp.period += tmp.original;
        queue.push(tmp);
    }
}