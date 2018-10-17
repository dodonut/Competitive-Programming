#include <cstdio>
#include <iostream>
#include <stack>
#include <sstream>

int main()
{
    int N, val, count = 0;
    bool invalid;
    std::stack<int> A, station;
    std::string line;

    while (scanf("%d ", &N), N)
    {
        while (getline(std::cin, line) && line != "0")
        {
            std::stringstream ss(line);
            invalid = false;

            while (!A.empty())
                A.pop();
            while (!station.empty())
                station.pop();
            for (int i = N; i >= 1; i--)
                A.push(i);

            while (ss >> val)
            {
                if (!A.empty() && A.top() == val)
                    A.pop();
                else if (!station.empty() && station.top() == val)
                {
                    station.pop();
                }
                else
                {
                    while (!A.empty() && val != A.top())
                    {
                        station.push(A.top());
                        A.pop();
                    }
                    if (A.empty())
                        invalid = true;
                    else
                        A.pop();
                }
            }
            if (invalid || !A.empty() || !station.empty())
                printf("No\n");
            else
                printf("Yes\n");
        }
        printf("\n");
    }
}