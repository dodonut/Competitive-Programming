#include <iostream>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main()
{
    //freopen("t.txt", "r", stdin);
    //freopen("tt.txt", "w", stdout);

    string line;
    int qtd = 0;
    bool valid;
    while (getline(cin, line))
    {
        valid = true;
        qtd = 0;
        for (int i = 0; i < line.size() && valid; i++)
        {
            if (line[i] == '(')
                qtd++;
            else if (line[i] == ')')
            {
                qtd--;
                if (qtd < 0)
                    valid = false;
            }
        }
        if (!valid || qtd != 0)
            printf("incorrect\n");
        else
            printf("correct\n");
    }
}
