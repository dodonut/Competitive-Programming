#include <cstdio>
#include <set>
#include <vector>

int main()
{
    int N, B, SG, SB, val;
    scanf("%d", &N);
    while (N--)
    {
        std::multiset<int> blue, green;
        scanf("%d %d %d", &B, &SG, &SB);
        for (int i = 0; i < SG; i++)
        {
            scanf("%d", &val);
            green.insert(val);
        }
        for (int i = 0; i < SB; i++)
        {
            scanf("%d", &val);
            blue.insert(val);
        }

        while (!blue.empty() && !green.empty())
        {
            int g, b;
            std::vector<int> gr, bl;
            for (int i = 0; i < B; i++)
            {
                if (green.empty() || blue.empty())
                    break;
                g = *green.rbegin(), b = *blue.rbegin();
                green.erase(--green.end()), blue.erase(--blue.end());
                int result = g - b;

                if (result < 0)
                    bl.push_back(-result);
                else if (result > 0)
                    gr.push_back(result);
            }
            while (!gr.empty())
            {
                green.insert(gr.front());
                gr.erase(gr.begin());
            }
            while (!bl.empty())
            {
                blue.insert(bl.front());
                bl.erase(bl.begin());
            }
        }

        if (blue.empty() && green.empty())
            printf("green and blue died\n");

        else if (blue.empty())
        {
            printf("green wins\n");
            for (auto c = green.rbegin(); c != green.rend(); c++)
                printf("%d\n", *c);
        }
        else
        {
            printf("blue wins\n");
            for (auto c = blue.rbegin(); c != blue.rend(); c++)
                printf("%d\n", *c);
        }
        if (N)
            printf("\n");
    }
}