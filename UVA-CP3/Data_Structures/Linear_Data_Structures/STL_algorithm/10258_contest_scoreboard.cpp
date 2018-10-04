#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int number_problems_solved[102], number_problems_unsolved[102][10], penalties[102];
bool contestants[102], problem_solved[102][10];
struct Contestant
{
    int contestant_number, problem_solved, penalty;
};

bool comp(const Contestant &a, const Contestant &b)
{
    if (a.problems_solved == b.problems_solved)
    {
        if (a.penalty == b.penalty)
            return a.contestant_number < b.contestant_number;
        return a.penalty < b.penalty;
    }
    return a.problems_solved > b.problems_solved;
}

int main()
{
    int T, contestant, problem, _time, count = 0;
    char status;
    std::vector<Contestant> to_print;
    std::string line;
    scanf("%d ", &T);
    while (T--)
    {
        if (count++ > 0)
            printf("\n");

        for (int i = 0; i < 102; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                number_problems_unsolved[i][j] = 0;
                problem_solved[i][j] = false;
            }
            number_problems_solved[i] = 0;
            penalties[i] = 0;
            contestants[i] = false;
        }
        to_print.clear();
        while (getline(std::cin, line) && line.size() > 0)
        {
            std::stringstream ss(line);
            sscanf(line.c_str(), "%d %d %d %c", &contestant, &problem, &_time, &status);
            contestants[contestant] = true;
            if (status == 'C' && !problem_solved[contestant][problem])
            {
                penalties[contestant] += _time + 20 * number_problems_unsolved[contestant][problem];
                number_problems_solved[contestant]++;
                problem_solved[contestant][problem] = true;
            }
            else if (status == 'I')
            {
                number_problems_unsolved[contestant][problem]++;
            }
        }

        for (int i = 1; i <= 100; i++)
        {
            if (contestants[i])
            {
                Contestant c;
                c.contestant_number = i;
                c.penalty = penalties[i];
                c.problems_solved = number_problems_solved[i];
                to_print.push_back(c);
            }
        }
        std::sort(to_print.begin(), to_print.end(), comp);
        for (auto &&k : to_print)
        {
            printf("%d %d %d\n", k.contestant_number, k.problems_solved, k.penalty);
        }
    }
}