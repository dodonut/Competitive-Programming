#include <iostream>
#include <vector>
#include <algorithm>

int prob_solved[26], prob_unsolved[26][8], penalties[26];
bool team_exist[26];
struct Team
{
    int problems_solved, penalties, team_number;
    bool operator<(const Team &b)
    {
        if (problems_solved == b.problems_solved)
        {
            if (penalties == b.penalties)
                return team_number < b.team_number;
            return penalties < b.penalties;
        }
        return problems_solved < b.problems_solved;
    }
};

int main()
{
    int n_team, hour, minutes;
    char status, problem;
    std::vector<Team> Teams;
    printf("RANK TEAM PRO/SOLVED TIME\n");
    while (scanf("%d %c %d:%d %c", &n_team, &problem, &hour, &minutes, &status) != EOF)
    {
        team_exist[n_team] = true;
        if (status == 'N')
        {
            prob_unsolved[n_team][problem - 'A']++;
        }
        else
        {
            prob_solved[n_team]++;
            penalties[n_team] += prob_unsolved[n_team][problem - 'A'] * 20 + hour * 60 + minutes;
        }

        for (int i = 0; i < 26; i++)
        {
            if (team_exist[i])
            {
                Team t;
                t.team_number = i;
                t.problems_solved = prob_solved[i];
                t.penalties = penalties[i];
                Teams.push_back(t);
            }
        }
    }
    std::sort(Teams.begin(), Teams.end());

    int current_rank = 1;
    for (int i = 0; i < Teams.size(); i++)
    {
        if (i > 0 && Teams[i].penalties == Teams[i - 1].penalties && Teams[i].problems_solved == Teams[i - 1].problems_solved)
            printf("%4d", current_rank);
        else
        {
            printf("%4d", i + 1);
            current_rank = i + 1;
        }
        printf(" %4d", Teams[i].team_number);
        if (Teams[i].problems_solved > 0)
            printf(" %4d %10d", Teams[i].problems_solved, Teams[i].penalties);
        printf("\n");
    }
}