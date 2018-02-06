#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<char, int> cardNumber;

int *cardNumberInOrder(string *hand)
{
	int *aux = new int[5];
	for (int i = 0; i < 5; i++)
	{
		aux[i] = cardNumber[hand[i][0]];
	}
	std::sort(aux, aux + 5);
	return aux;
}

int straightFlush(string *hand)
{
	int *aux = new int[5];
	aux = cardNumberInOrder(hand);
	for (int i = 0; i < 4; i++)
	{
		if (hand[i][1] != hand[i + 1][1] || aux[i] != (aux[i + 1] - 1))
			return 0;
	}
	return 9 * 10 + aux[4];
}

int fourOfKind(string *hand)
{
	int *aux = new int[5];
	aux = cardNumberInOrder(hand);
	if (aux[0] != aux[1])
		return 0;
	if (aux[3] != aux[4])
		return 0;
	return 8 * 10 + aux[2];
}

int fullHouse(string *hand)
{
	int *aux = new int[5];
	aux = cardNumberInOrder(hand);
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

	int *aux = new int[5];
	aux = cardNumberInOrder(hand);

	return 6 * 10 + aux[4];
}

int straight(string *hand)
{
	int *aux = new int[5];
	aux = cardNumberInOrder(hand);
	for (int i = 0; i < 4; i++)
	{
		if (aux[i] != (aux[i + 1] - 1))
			return 0;
	}
	return 5 * 10 + aux[4];
}

int threeOfKind(string *hand)
{
	int *aux = new int[5];
	aux = cardNumberInOrder(hand);
	if (aux[0] == aux[1] && aux[1] == aux[2])
		return 4 * 10 + aux[0];
	if (aux[1] == aux[2] && aux[2] == aux[3])
		return 4 * 10 + aux[1];
	if (aux[2] == aux[3] && aux[3] == aux[4])
		return 4 * 10 + aux[2];
	return 0;
}

std::pair<int, int> findPair(string *hand, int condition = 0)
{
	int *aux = new int[5];
	aux = cardNumberInOrder(hand);
	std::pair<int, int> p = make_pair(0, 0);
	int last;
	for (int i = 0; i < 4; i++)
	{
		if (aux[i] == aux[i + 1])
		{
			p.first++;
			last = p.second;
			p.second = aux[i];
		}
	}
	if (condition)
		p.second = last;
	return p;
}

std::pair<int, int> twoPairs(string *handBlack, string *handWhite)
{
	std::pair<int, int> pB = findPair(handBlack);
	std::pair<int, int> pW = findPair(handBlack);
	int blackPoints = 0, whitePoints = 0;
	if (pB.first == 2)
		blackPoints += 3 * 10 + pB.second;
	if (pW.first == 2)
		whitePoints += 3 * 10 + pW.second;
	if (blackPoints == whitePoints && (blackPoints || whitePoints))
	{
		pB = findPair(handBlack, 1);
		pW = findPair(handWhite, 1);

		if (pB.second != pW.second)
		{
			if (pB.first == 2)
				blackPoints += 3 * 10 + pB.second;
			if (pW.first == 2)
				whitePoints += 3 * 10 + pW.second;
		}
		else
		{
			int *aux1 = new int[5];
			aux1 = cardNumberInOrder(handBlack);
			int *aux2 = new int[5];
			aux2 = cardNumberInOrder(handWhite);
			if (pB.first == 2)
			{
				if (aux1[0] != aux1[1] && aux1[1] == aux1[2])
					blackPoints += 3 * 10 + aux1[0];
				else if (aux1[2] != aux1[1] && aux1[2] != aux1[3])
					blackPoints += 3 * 10 + aux1[2];
				else
					blackPoints += 3 * 10 + aux1[4];
			}
			if (pW.first == 2)
				if (aux2[0] != aux2[1] && aux2[1] == aux2[2])
					whitePoints += 3 * 10 + aux2[0];
				else if (aux2[2] != aux2[1] && aux2[2] != aux2[3])
					whitePoints += 3 * 10 + aux2[2];
				else
					whitePoints += 3 * 10 + aux2[4];
		}
	}
	return make_pair(blackPoints, whitePoints);
}

std::pair<int, int> Pair(string *handBlack, string *handWhite)
{
	std::pair<int, int> pB = findPair(handBlack);
	std::pair<int, int> pW = findPair(handBlack);
	int blackPoints = 0, whitePoints = 0;
	if (pB.first == 1)
		blackPoints += 2 * 10 + pB.second;
	if (pW.first == 1)
		whitePoints += 2 * 10 + pW.second;
	if (blackPoints == whitePoints && (blackPoints || whitePoints))
	{
		int *aux1 = new int[5];
		aux1 = cardNumberInOrder(handBlack);
		int *aux2 = new int[5];
		aux2 = cardNumberInOrder(handWhite);
		int i;
		for (i = 4; i >= 0; i--)
		{
			if (aux1[i] != aux2[i])
				break;
		}
		blackPoints = 2 * 10 + aux1[i];
		whitePoints = 2 * 10 + aux2[i];
	}
	return make_pair(blackPoints, whitePoints);
}

std::pair<int, int> highCard(string *handBlack, string *handWhite)
{
	int *aux1 = new int[5];
	aux1 = cardNumberInOrder(handBlack);
	int *aux2 = new int[5];
	aux2 = cardNumberInOrder(handWhite);
	int i;

	for (i = 4; i >= 0; i--)
	{
		if (aux1[i] != aux2[i])
			break;
	}
	if (i < 0)
		i = 0;
	return make_pair(10 + aux1[i], 10 + aux2[i]);
}

int main()
{

	char cards[]{'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	for (int i = 0; i < 13; i++)
		cardNumber[cards[i]] = i + 2;

	string white[5], black[5];

	char input;
	while (cin >> input)
	{
		cin.putback(input);
		for (int i = 0; i < 5; i++)
			cin >> black[i];
		for (int i = 0; i < 5; i++)
			cin >> white[i];

		int blackPoints = 0, whitePoints = 0;

		blackPoints += straightFlush(black) + fourOfKind(black) + fullHouse(black) + straight(black) + threeOfKind(black);

		whitePoints += straightFlush(white) + fourOfKind(white) + fullHouse(white) + straight(white) + threeOfKind(white);

		if (blackPoints == whitePoints)
		{
			std::pair<int, int> p, temp;
			p = twoPairs(black, white);

			if (p.first == 0 && p.second == 0)
				temp = Pair(black, white);
			p.first += temp.first;
			p.second += temp.second;

			if (p.first == 0 && p.second == 0)
				temp = highCard(black, white);
			p.first += temp.first;
			p.second += temp.second;

			if (p.first == p.second)
				cout << "Tie." << endl;
			else if (p.first > p.second)
				cout << "Black wins." << endl;
			else
				cout << "White wins." << endl;
		}
		else if (blackPoints > whitePoints)
			cout << "Black wins." << endl;
		else
			cout << "White wins." << endl;
	}
}