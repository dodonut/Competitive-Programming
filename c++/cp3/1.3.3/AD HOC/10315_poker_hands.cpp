#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int straightFlush(string *hand)
{
    int aux[5];
    for (int i = 0; i < 5; i++)
        aux[i] = hand[i][0] - '0';
    std::sort(aux, aux + 5);
    for (int i = 0; i < 4; i++)
    {
        if (hand[i][1] != hand[i + 1][1] || aux[i] != (aux[i + 1] - 1))
            return 0;
    }
    return 9 * 10 + aux[4];
}

int fourOfKind(string *hand)
{
    int aux[5];
    for (int i = 0; i < 5; i++)
        aux[i] = hand[i][0] - '0';
    std::sort(aux, aux + 5);
    if (aux[0] != aux[1])
        return 0;
    if (aux[3] != aux[4])
        return 0;
    return 8 * 10 + aux[2];
}

int fullHouse(string *hand)
{
    int aux[5];
    for (int i = 0; i < 5; i++)
        aux[i] = hand[i][0] - '0';
    std::sort(aux, aux + 5);
    if (aux[0] == aux[1])
    {
        if (aux[1] == aux[2] && aux[3] == aux[4])
            return 7 * 10 + aux[0];
        else if (aux[4] == aux[3] && aux[3] == aux[2])
            return 7 * 10 + aux[2];
    }
    return 0;
}

int flush(string *hand)
{
    for (int i = 0; i < 4; i++)
    {
        if (hand[i][1] != hand[i + 1][1])
            return 0;
    }

    int aux[5];
    for (int i = 0; i < 5; i++)
        aux[i] = hand[i][0] - '0';
    std::sort(aux, aux + 5);

    return 6 * 10 + aux[4];
}

int straight(string *hand)
{
    int aux[5];
    for (int i = 0; i < 5; i++)
        aux[i] = hand[i][0] - '0';
    std::sort(aux, aux + 5);
    for (int i = 0; i < 4; i++)
    {
        if (aux[i] != (aux[i + 1] - 1))
            return 0;
    }
    return 5 * 10 + aux[4];
}

int threeOfKind(string *hand)
{
    int aux[5];
    for (int i = 0; i < 5; i++)
        aux[i] = hand[i][0] - '0';
    std::sort(aux, aux + 5);
    if (aux[0] == aux[1] && aux[1] == aux[2])
        return 4 * 10 + aux[0];
    if (aux[1] == aux[2] && aux[2] == aux[3])
        return 4 * 10 + aux[1];
    if (aux[2] == aux[3] && aux[3] == aux[4])
        return 4 * 10 + aux[2];
    return 0;
}

int twoPairs(string *hand)
{
}

int main()
{
    string white[5], black[5];

    for (int i = 0; i < 5; i++)
        cin >> black[i];
    for (int i = 0; i < 5; i++)
        cin >> white[i];

    cout << straightFlush(black);
}