#include <iostream>
#include <stack>
#include <queue>
#include <vector>

struct station
{
    std::queue<int> plataformB;
};

bool all_empty(std::vector<station> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!s[i].plataformB.empty())
            return false;
    }
    return true;
}

int main()
{
    int minutes, set, N, S, Q, cargoes, cargo, curr_station;
    scanf("%d", &set);
    while (set--)
    {
        minutes = 0;
        std::stack<int> cargo_carrier;
        std::vector<station> st(N);
        scanf("%d %d %d", &N, &S, &Q);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &cargoes);
            while (cargoes--)
            {
                scanf("%d", &cargo);
                st[i].plataformB.push(cargo);
            }
        }

        curr_station = 0;
        while (!all_empty(st))
        {
            while (!cargo_carrier.empty() && cargo_carrier.top() != curr_station)
            {
                if (st[curr_station].plataformB.size() < Q)
                {
                    st[curr_station].plataformB.push(cargo_carrier.top());
                    cargo_carrier.pop();
                    minutes++;
                }
                else
                    break;
            }
            if (!cargo_carrier.empty() && cargo_carrier.top() == curr_station)
            {
                cargo_carrier.pop();
                minutes++;
            }
            while (cargo_carrier.size() < S)
            {
                cargo_carrier.push(st[curr_station].plataformB.front());
                st[curr_station].plataformB.pop();
                minutes++;
            }
            curr_station = (curr_station + 1) % N;
        }
    }
}