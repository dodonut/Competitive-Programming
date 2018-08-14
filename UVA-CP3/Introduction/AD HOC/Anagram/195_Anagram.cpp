#include <iostream>
#include <algorithm>

bool compare(char a, char b)
{
    if (tolower(a) == tolower(b))
        return a < b;
    return tolower(a) < tolower(b);
}

int main()
{
    int N;
    std::string word;
    scanf("%d", &N);
    while (N--)
    {
        std::cin >> word;
        std::sort(word.begin(), word.end(), compare);
        do
        {
            std::cout << word << '\n';
        } while (std::next_permutation(word.begin(), word.end(), compare));
    }
}