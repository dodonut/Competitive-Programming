#include <iostream>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //freopen("t.txt", "r", stdin);
    //freopen("tt.txt", "w", stdout);

    int T, qtd;
    vector<string> t;
    string tel;
    while (scanf("%d", &T) != EOF)
    {
        t.clear();
        qtd = 0;
        while (T--)
        {
            cin >> tel;
            t.push_back(tel);
        }
        sort(t.begin(), t.end());
        for (int i = 1; i < t.size(); i++)
        {
            for (int j = 0; j < t[i].size(); j++)
            {
                if (t[i][j] == t[i - 1][j])
                    qtd++;
                else
                    break;
            }
        }

        printf("%d\n", qtd);
    }
}
