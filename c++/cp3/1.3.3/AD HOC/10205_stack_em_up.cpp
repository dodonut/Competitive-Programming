#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	cout << "here" << endl;

	string names[]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
	string suits[]{"Clubs", "Diamonds", "Hearts", "Spades"};
	map<int, string> mapDeck;
	int counter = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
			mapDeck[counter++] = names[j] + " of " + suits[i];
	}
	int deckShuffles[102][52];
	int deck[52], tempDeck[52];
	string line;

	for (int i = 0; i < 52; i++)
		deck[i] = i + 1;

	int T, knownShuffles;
	cin >> T;
	while (T--)
	{
		cin >> knownShuffles;
		for (int k = 1; k <= knownShuffles; k++)
		{
			for (int i = 0; i < 52; i++)
			{
				cin >> deckShuffles[k][i];
			}
		}

		getline(cin, line);
		while (!line.empty())
		{
			for (int i = 0; i < 52; i++)
				tempDeck[i] = deck[i];
			for (int i = 0; i < 52; i++)
				deck[i] = tempDeck[deckShuffles[stoi(line)][i] - 1];
			getline(cin, line);
		}

		for (int i = 0; i < 52; i++)
			printf("%s\n", mapDeck[deck[i]].c_str());
		cout << endl;
	}
}
