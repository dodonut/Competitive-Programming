#include <iostream>
#include <vector>
#include <sstream>

int main()
{
    int T, n, k;
    int count = 0;
    std::stringstream s1;
    std::vector<int> index;
    std::vector<std::string> permuted;
    std::string line, d;

    std::cin >> T;
    std::cin.ignore();
    while (T--)
    {
        k = 0;
        index.clear();
        permuted.clear();
        getline(std::cin, line);
        s1 << line;
        while (s1 >> n)
            index.push_back(n);

        permuted.resize(index.size());
        for (int i = 0; i < index.size(); i++)
        {
            std::cin >> d;
            permuted[index[k++] - 1] = d;
        }

        for (auto &i : permuted)
            std::cout << i << '\n';

        if (T)
            std::cout << '\n';
    }
}