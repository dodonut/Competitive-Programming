#include <iostream>

long long reverse(const long long &n)
{
    std::string tmp, aux;
    tmp = std::to_string(n);
    aux = "";
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        aux += tmp[i];
    }
    return stoull(aux);
}

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

std::pair<int, long long> find_palindrome(const long long &n)
{
    long long reversed_n = n;
    int i;
    for (i = 1; i <= 1000; i++)
    {
        reversed_n += reverse(reversed_n) + reversed_n;
        if (is_pal(std::to_string(reversed_n)))
            return std::make_pair(i, reversed_n);
    }
    return std::make_pair(0, 0ll);
}

int main()
{
    int N;
    long long result;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%lld", result);
        auto tmp = find_palindrome(result);
        printf("%d %lld\n", tmp.first, tmp.second);
    }
}