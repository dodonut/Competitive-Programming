#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    char buff[32], c;
    std::string input;
    int score;
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

    while (true)
    {
        score = 0;
        frame = 0;
        play = 0;
        scanf(" %[^\n]", buff);
        input = buff;
        if (input == "Game Over")
            break;

        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
        printf("input a: %s\n", input.c_str());

        for (auto i = 0ul; i < input.length(); i++)
        {
            c = input[i];
            play++;
            score += valueOf(c);
            if (c == '/' && frame < 10)
                score += valueOf(input[i + 1]);
            else if (c == 'X' && frame < 10)
                score += valueOf(input[i + 1]) + valueOf(input[i + 2]);

            if (play == 2 || c == '/' || c == 'X')
            {
                frame++;
                play = 0;
            }
        }
        printf("%d\n", score);
    }
    return 0;
}