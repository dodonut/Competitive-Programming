#include <iostream>
#include <vector>
#include <sstream>

#define ii std::pair<int, int>
int max_time = 60 * 60 + 1;

bool all_signals_green(int time, std::vector<int> &vec_cycles)
{

    for (int i = 0; i < vec_cycles.size(); i++)
    {
        if ((time % (vec_cycles[i] * 2)) >= (vec_cycles[i] - 5))
            return false;
    }
    return true;
}

int main()
{
    std::vector<int> vec_signals;
    std::string line;
    int cycle, lowerst_cycle, count_cycles, count = 1;

    while (getline(std::cin, line))
    {
        count_cycles = 0;
        std::stringstream ss(line);
        vec_signals.clear();
        lowerst_cycle = 90;
        while (ss >> cycle)
        {
            vec_signals.push_back(cycle);
            if (cycle < lowerst_cycle)
                lowerst_cycle = cycle;
        }
        count_cycles = lowerst_cycle * 2;
        while (!all_signals_green(count_cycles, vec_signals) && count_cycles < max_time)
            ++count_cycles;

        printf("Set %d ", count++);
        if (count_cycles < max_time)
            printf("synchs again at %d minute(s) and %d second(s) after all turning green.\n", count_cycles / 60, count_cycles % 60);
        else
            printf("is unable to synch after one hour.\n");
    }
}