#include <iostream>
#include <queue>
#include <stack>
#include <vector>

bool all_empty(const std::vector<std::queue<int>> &stations)
{
    for (auto &&a : stations)
    {
        if (!a.empty())
            return false;
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, SET, N, S, Q, Qi, Qi_cargo;
    scanf("%d", &SET);
    while (SET--)
    {
        std::stack<int> cargo_carrier;
        scanf("%d%d%d", &N, &S, &Q);
        std::vector<std::queue<int>> stations(N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &Qi);
            while (Qi--)
            {
                scanf("%d", &Qi_cargo);
                stations[i].push(Qi_cargo);
            }
        }
        int minutes = 0;
        int current_station = 0;
        while (!all_empty(stations))
        {
            while (!cargo_carrier.empty())
            {
                int cargo = cargo_carrier.top();
                minutes++;
                if (cargo != current_station + 1)
                {
                    if (stations[current_station].size() < Q)
                    {
                        cargo_carrier.pop();
                        stations[current_station].push(cargo);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    cargo_carrier.pop();
                }
            }

            while (cargo_carrier.size() < S && !stations[current_station].empty())
            {
                int cargo = stations[current_station].front();
                cargo_carrier.push(cargo);
                stations[current_station].pop();
                minutes++;
            }

            current_station = (current_station + 1) % N;
        }
        printf("%d\n", minutes);
    }
}