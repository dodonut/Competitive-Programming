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
    Problem p[8];
    int n_prob_solved, total_time, team_number;
    Team()
    {
        n_prob_solved = 0;
        team_number = 27;
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
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, max_contest, h, m, nt;
    char line[15], s, p;
    Team teams[26];
    scanf("%d ", &n);
    while (n--)
    {
        max_contest = 1;
        for (int i = 0; i < 26; i++)
        {
            Team t;
            t.team_number = i;
            teams[i] = t;
        }

        printf("RANK TEAM PRO/SOLVED TIME\n");
        while (fgets(line, 15, stdin) != NULL && line[0] != '\n')
        {
            sscanf(line, "%d %c %d:%d %c", &nt, &p, &h, &m, &s);
            if (max_contest < nt)
                max_contest = nt;
            if (s == 'Y')
            {
                teams[nt].n_prob_solved++;
                teams[nt].p[p - 'A'].solved_time = h * 60 + m;
                teams[nt].p[p - 'A'].solved = true;
            }
            teams[nt].p[p - 'A'].submissions.insert(h * 60 + m);
        }

        for (int i = 1; i <= max_contest; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (teams[i].p[j].solved)
                {
                    for (auto &k : teams[i].p[j].submissions)
                    {
                        if (teams[i].p[j].solved_time != k)
                            teams[i].total_time += 20;
                        else
                        {
                            teams[i].total_time += k;
                            break;
                        }
                    }
                }
            }
        }

        std::sort(teams, teams + max_contest, comp);
        int rank = 1;
        for (int i = 1; i < max_contest; i++)
        {
            printf("%4d%5d%5d%11d\n", rank, teams[i].team_number, teams[i].n_prob_solved, teams[i].total_time);
            if (i > 1 && !(teams[i].n_prob_solved == teams[i - 1].n_prob_solved && teams[i].total_time == teams[i - 1].total_time))
            {
                rank = i;
            }
        }
    }
}
