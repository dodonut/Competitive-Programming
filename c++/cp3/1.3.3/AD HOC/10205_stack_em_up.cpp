#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <limits>
#define iter(a, b, c, d) for (a = b; a < c; a += d)
#define ited(a, b, c, d) for (a = b; a > c; a -= d)
#define li long int
#define uli unsigned li
#define ll long li
#define ull unsigned ll
#define si(a) scanf("%d", &a)
#define sli(a) scanf("%ld", &a)
#define sll(a) scanf("%lld", &a)
#define slu(a) scanf("%llu", &a)
#define sf(a) scanf("%f", &a)
#define slf(a) scanf("%lf", &a)
#define PI 3.1415926
using namespace std;

map<int, string> mountDeck()
{
	string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	string numbers[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

	map<int, string> deck;
	int i, j, counter = 1;
	string card;
	iter(i, 0, 4, 1)
	{
		iter(j, 0, 13, 1)
		{
			card += numbers[j] + " of " + suits[i];
			deck[counter++] = card;
			card = "";
		}
	}
	return deck;
}

vector<int> doShuffles(vector<int> temp, vector<int> now, vector<int> shuff)
{
	int i;
	iter(i, 0, 52, 1)
	{
		now.at(i) = temp.at(shuff.at(i) - 1);
	}

	cout << now.at(i) << endl;
	return now;
}

int main()
{
	map<int, string> deckMap = mountDeck();
	vector<int> ans, now;
	vector<vector<int>> shuffles;

	int testCases;
	int card, i, shf;
	string line, Card;

	iter(i, 0, 52, 1) now.push_back(i + 1);

	cin >> testCases;
	while (testCases--)
	{
		cin >> shf;

		int c = shf;
		while (c--)
		{
			iter(i, 0, 52, 1)
			{
				cin >> card;
				ans.push_back(card);
			}
			shuffles.push_back(ans);
			ans.clear();
		}
		cin.ignore();
		getline(cin, line);
		while (!line.empty())
		{
			now = doShuffles(now, now, shuffles.at(std::stoi(line) - 1));
			getline(cin, line);
		}

		iter(i, 0, 52, 1)
		{
			Card = deckMap[now[i]];
			//printf("%s\n", Card.c_str());
		}
		cout << endl;
		//iter(i, 0, shuffles.size(), 1) shuffles[i].clear();
		//shuffles.clear();
		now.clear();
		ans.clear();
		shuffles.clear();
	}
}