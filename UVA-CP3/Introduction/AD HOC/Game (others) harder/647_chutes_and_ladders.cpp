#include <iostream>
#include <vector>
#include <map>

struct Ladder
{
    int start, end;
    Ladder(int s, int e) : start(s), end(e) {}
};

int main()
{
    int dieroll, n_players;
    std::vector<int> dieset;
    while (scanf("%d", &dieroll), dieroll)
        dieset.push_back(dieroll);

    int start, end;
    int extraFunc;
    std::map<int,int> ladders;
    std::vector<int> extras(105);
    int player_turn;
    int temp_point;
    while (scanf("%d", &n_players), n_players)
    {
        player_turn = 0;
        while (scanf("%d %d", &start, &end), start && end)
            ladders[start] = end;

        while (scanf("%d", &extraFunc), extraFunc)
        {
            if (extraFunc < 0)
                extras[abs(extraFunc)] = 1;
            else
                extras[extraFunc] = 2;
        }

        std::vector<int> player_points(n_players);

        for (auto&& dieroll : dieset){
            temp_point = player_points[player_turn] + dieroll;
            if (extras[temp_point] == 1) {
                player_turn = (player_turn + 1) % n_players;
                continue;
            }
            if (temp_point <= 100){
                if (ladders.count(temp_point)) temp_point = ladders[temp_point];
                player_points[player_turn] = temp_point;
                if (temp_point == 100) break;
                if (extras[temp_point] == 0) player_turn = (player_turn + 1) % n_players;
            }
        }

        printf("%d\n", player_turn + 1);

        ladders.clear();
        extras.clear();
        
    }
}