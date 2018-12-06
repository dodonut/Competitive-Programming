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
        while (true)
        {
            while (!cargo_carrier.empty() && (stations[current_station].size() < Q || cargo_carrier.top() == current_station + 1))
            {
                if (cargo_carrier.top() == current_station + 1)
                    cargo_carrier.pop();
                else
                {
                    stations[current_station].push(cargo_carrier.top());
                    cargo_carrier.pop();
                }
                minutes++;
            }

            while (cargo_carrier.size() < S && !stations[current_station].empty())
            {
                cargo_carrier.push(stations[current_station].front());
                stations[current_station].pop();
                minutes++;
            }

            current_station = (current_station + 1) % N;
            if (cargo_carrier.empty() && all_empty(stations))
                break;

            minutes += 2;
        }
        printf("%d\n", minutes);
    }
}