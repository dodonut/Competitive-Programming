#include <iostream>
#include <vector>

int main()
{
    int T, N, count = 1, tot_p, tot_q;
    bool flag;
    std::vector<int> F(100002), S(100002);
    scanf("%d", &T);
    while (T--)
    {
        flag = false;
        tot_p = 0;
        tot_q = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &F[i]);
            tot_p += F[i];
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &S[i]);
            tot_q += S[i];
        }
        printf("Case %d: ", count++);
        if (tot_p < tot_q)
            printf("Not possible\n");
        else
        {
            for (int i = 0; i < N; i++)
            {
                tot_p = 0;
                flag = false;
                int j = i;
                do
                {
                    tot_p += F[j] - S[j];
                    if (tot_p < 0)
                        flag = true;
                    j = (j + 1) % N;
                } while (!flag);

                if (!flag)
                {
                    printf("Possible from station %d\n", i + 1);
                    break;
                }
            }
        }
    }
}