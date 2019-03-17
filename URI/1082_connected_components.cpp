#include <iostream>
#include <vector>
#include <set>

std::set<int> toPrint;

int visit(int visited[], std::vector<int> graph[], int value)
{
    if (!visited[value])
        toPrint.insert(value);
    visited[value] = 1;
    for (int i = 0; i < graph[value].size(); i++)
    {
        int v2 = graph[value][i];
        if (!visited[v2])
        {
            visit(visited, graph, v2);
        }
    }
}

int main()
{

    int tc, v, e, c = 1;
    char c1, c2;
    std::vector<int> graph[28];
    int visited[28];
    int components;
    scanf("%d", &tc);
    while (tc--)
    {
        components = 0;
        for (int i = 0; i < 28; i++)
        {
            graph[i].clear();
            visited[i] = 0;
        }
        scanf("%d%d ", &v, &e);
        for (int i = 0; i < e; i++)
        {
            scanf(" %c %c", &c1, &c2);
            int v1 = c1 - 'a', v2 = c2 - 'a';
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        printf("Case #%d:\n", c++);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                visit(visited, graph, i);
                for (auto k : toPrint)
                    printf("%c,", k + 'a');
                toPrint.clear();
                printf("\n");
                components++;
            }
        }
        printf("%d connected components\n\n", components);
    }
}