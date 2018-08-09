#include <iostream>

bool is_pal(const std::string &word)
{
    int size = word.size(), i;
    for (i = 0; i < size / 2; i++)
    {
        if (word[i] != word[size - 1 - i])
            return false;
    }
    return true;
}

std::string get_hours(int h, int m)
{
    char t[10];
    if (h == 0)
        sprintf(t, "%d", m);
    else
        sprintf(t, "%d%02d", h, m);
    return t;
}

std::string next_pal(int h, int m)
{
    int i, j = m + 1;
    std::string tmp;
    char t[30];
    for (i = h;; i = (i + 1) % 24)
    {
        for (; j < 60; j++)
        {
            tmp = get_hours(i, j);
            if (is_pal(tmp))
            {
                sprintf(t, "%02d:%02d", i, j);
                return t;
            }
        }
        j = 0;
    }
}

int main()
{
    int h, m, N;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d:%d", &h, &m);
        printf("%s\n", next_pal(h, m).c_str());
    }
}