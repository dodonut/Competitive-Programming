#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

struct Problem
{
    bool solved;
    int solved_time;
    std::set<int> submissions;
    Problem()
    {
        solved = false;
        solved_time = 0;
        submissions.clear();
    }
};

struct Team
{
    std::vector<Problem> p;
    int n_prob_solved, total_time, team_number;
    Team()
    {
        p.reserve(8);
        n_prob_solved = 0;
    }
};

bool comp(const Team &a, const Team &b)
{
    if (a.n_prob_solved == b.n_prob_solved)
    {
        if (a.total_time == b.total_time)
            return a.team_number < b.team_number;
        return a.total_time < b.total_time;
    }
    return a.n_prob_solved > b.n_prob_solved;
}

int main()
{
    int n, max_contest, h, m, nt;
    char line[15], s, p;
    std::vector<Team> teams(26), kt;
    scanf("%d", &n);
    while (n--)
    {
        max_contest = 1;
        teams.clear();
        kt.clear();

        printf("RANK TEAM PRO/SOLVED TIME\n");
        while (fgets(line, 15, stdin) != NULL && line[0] != '\n')
        {
            sscanf(line, "%d %c %d:%d %c", &nt, &p, &h, &m, &s);
            if (max_contest < nt)
                max_contest = nt;
            if (s == 'Y')
            {
                teams[nt].n_prob_solved++;
                teams[nt].p[p].solved_time = h * 60 + m;
            }
            teams[nt].p[p].submissions.insert(h * 60 + m);
        }

        for (int i = 1; i <= max_contest; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                for (auto &k : teams[i].p[j].submissions)
                {
                }
            }
        }
    }
}
