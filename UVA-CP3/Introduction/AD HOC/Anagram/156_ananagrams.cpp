#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

std::map<std::string,int> words;
std::set<std::string> dict;

std::string to_lower(const std::string &line)
{
    std::string tmp = line;
    for (auto &&i : tmp)
    {
        i = std::tolower(i);
    }
    return tmp;
}

int main(){
    std::string line, word;
    while(getline(std::cin, line), line != "#"){
        std::stringstream ss(line);
        while(ss >> word){
            dict.insert(word);
            word = to_lower(word);
            std::sort(word.begin(), word.end());
            words[word]++;
        }
    }

    for(auto&& w : dict){
        word = w;
        word = to_lower(word);
        std::sort(word.begin(), word.end());
        if(words[word] == 1) printf("%s\n",w.c_str());
    }
}