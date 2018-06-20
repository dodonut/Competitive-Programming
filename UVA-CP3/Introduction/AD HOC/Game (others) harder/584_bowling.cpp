#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char c;
    std::string input;
    int score, tempVal;
    int frame, play = 0;

    auto valueOf = [](char &c) {
        if (c >= '0' && c <= '9')
            return c - '0';
        else if (c == '/')
            return 10;
        else if (c == 'X')
            return 10;
        return 0;
    };

    while (std::getline(std::cin, input) && input != "Game Over")
    {
        score = 0;
        frame = 0;
        play = 0;
        tempVal = 0;

        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

        for (auto i = 0ul; i < input.length(); i++)
        {
            c = input[i];
            tempVal += valueOf(c);
            play++;
            if (frame >= 10)
                break;
            if (play > 1)
            {
                if (c == '/')
                    score += 10 + valueOf(input[i + 1]);
                else
                    score += tempVal;
                frame++;
                play = 0;
                tempVal = 0;
            }
            else if (c == 'X')
            {
                score += input[i + 2] == '/' ? 20 : 10 + valueOf(input[i + 1]) + valueOf(input[i + 2]);
                frame++;
                play = 0;
                tempVal = 0;
            }
        }
        std::cout << score << '\n';
    }
    return 0;
}
