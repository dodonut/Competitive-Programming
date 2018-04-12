#include <iostream>

int m[12][42];

void rm(int r, int c, int value){
    if(m[r][c] == 0 || m[r][c] == value){
        rm(r-)
    }
}

bool Remove(int r, int c, int value){

}

int main()
{
    int M, N, i, j, r, c;
    while (scanf("%d %d", &M, &N), M && N)
    {
        for (i = 1; i <= M; i++)
            for (j = 1; j <= N; j++)
                scanf("%d", m[i][j]);

        while (scanf("%d %d", &r, &c), r)
        {
            if (Remove(r, c, m[r][c]))
            {
                if (!moveRowElem(c))
                {
                    moveColElem(c);
                    moveRowElem(c);
                }
            }
        }

        for (i = 0; i < 12; i++)
            for (j = 0; j < 42; j++)
                m[i][j] = 0;
    }
}