#include <iostream>
#include <cstring>
#include <map>

int main()
{
    int T, total;
    char line[31];
    scanf("%d ", &T);
    while (T--)
    {
        total = 0;
        std::map<std::string, int> trees;

        while (fgets(line, 30, stdin) && strcmp(line, "\n") != 0)
        {
            line[strlen(line) - 1] = '\0';
            trees[line]++;
            total++;
        }

        for (auto &&v : trees)
        {
            printf("%s %.4f\n", v.first.c_str(), (double)(v.second * 100) / total);
        }
        if (T)
            printf("\n");
    }
}