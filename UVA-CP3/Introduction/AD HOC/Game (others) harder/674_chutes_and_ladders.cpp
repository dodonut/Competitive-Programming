#include <iostream>
#include <vector>

struct Ladder
{
    int start, end;
    Ladder(int s, int e) : start(s), end(e) {}
};

int main()
{
    int dieroll, n_players, player_turn;
    std::vector<int> dieset;
    while (scanf("%d", &dieroll), dieroll)
        dieset.push_back(dieroll);

    int start, end;
    int extraFunc;
    std::vector<Ladder> ladders;
    std::vector<int> extras(105);
    while (scanf("%d", &n_players), n_players)
    {
        while (scanf("%d %d", &start, &end), start && end)
            ladders.push_back(Ladder(start, end));

        while (scanf("%d", &extraFunc), extraFunc)
        {
            if (extraFunc < 0)
                extras[abs(extraFunc)] = 1;
            else
                extras[extraFunc] = 2;
        }
        
    }
}