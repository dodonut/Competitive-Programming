#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

std::vector<std::string> dictionary, anagrams_words, words;
std::vector<int> letter_count(30);
int qtd_letters_used;
std::string current_phrase;
std::set<std::string> originalSet;

void find_anagrams(int dict_index)
{
    if (qtd_letters_used == 0)
    {
        printf("%s =", current_phrase.c_str());
        for (auto &word : anagrams_words)
            printf(" %s", word);
        printf("\n");
        return;
    }
    auto tmp_letters_count = letter_count;
    int tmp_letters_used = qtd_letters_used;
    for (; dict_index < dictionary.size(); dict_index++)
    {
        if (originalSet.find(dictionary[dict_index]) != originalSet.end())
        {
            printf("word analised: %s\n", dictionary[dict_index].c_str());
            bool able_to_mount_word = true;
            for (auto &c : dictionary[dict_index])
            {
                letter_count[c - 'A']--;
                if (letter_count[c - 'A'] < 0)
                {
                    able_to_mount_word = false;
                    break;
                }
                qtd_letters_used--;
            }
            if (able_to_mount_word)
            {
                anagrams_words.push_back(dictionary[dict_index]);
                find_anagrams(dict_index + 1);
                anagrams_words.pop_back();
            }
            else
            {
                letter_count = tmp_letters_count;
                qtd_letters_used = tmp_letters_used;
            }
        }
    }
}

int main()
{
    std::string line;
    while (getline(std::cin, line), line != "#")
    {
        dictionary.push_back(line);
    }

    while (getline(std::cin, line), line != "#")
    {
        current_phrase = line;

        anagrams_words.clear();
        letter_count.clear();
        std::stringstream ss;
        std::string tmp;
        while (ss >> tmp)
            originalSet.insert(tmp);
        for (auto &c : line)
        {
            if (c != ' ')
            {
                letter_count[c - 'A']++;
                qtd_letters_used++;
            }
        }
        find_anagrams(0);
    }
}