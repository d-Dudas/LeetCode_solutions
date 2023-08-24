#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Solution {
public:
    string fullJustifyHelper(string& input, int maxWidth)
    {
        if(input.size() == maxWidth) return input;

        vector<string> words;
        string word;
        stringstream ss(input);

        while(ss >> word)
        {
            words.push_back(word);
        }

        int wordsCount = words.size();

        if(wordsCount == 1)
        {
            while(input.size() != maxWidth) input += " ";
            return input;
        }

        int spacesToAdd = maxWidth - input.size();
        int spacesToAddBetweenWords = spacesToAdd / (wordsCount - 1);
        int bonusSpaces = spacesToAdd % (wordsCount - 1);

        string spaces = "";
        for(int i = 0; i < spacesToAddBetweenWords; i++) spaces += " ";

        string result;
        for(auto& w : words)
        {
            if(result.size() != 0) result += " ";
            result += w;
            if(spacesToAdd > 0)
            {
                if(bonusSpaces > 0)
                {
                    result += " ";
                    spacesToAdd--;
                    bonusSpaces--;
                }

                result += spaces;
                spacesToAdd -= spacesToAddBetweenWords;
            }
        }

        return result;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string line;
        for(auto& word : words)
        {
            if(line.size() + word.size() + 1 <= maxWidth)
            {
                line += line.size() == 0 ? "" : " ";
                line += word;
            } else if(line.size() == 0 && word.size() == maxWidth) {
                result.push_back(word);
            } else {
                result.push_back(fullJustifyHelper(line, maxWidth));
                line = word;
            }
        }

        if(line.size() > 0)
        {
            while(line.size() != maxWidth) line += " ";
            result.push_back(line);
        }
        
        return result;
    }
};

int main()
{
    vector<string> words = {"Give","me","my","Romeo;","and,","when","he","shall","die,","Take","him","and","cut","him","out","in","little","stars,","And","he","will","make","the","face","of","heaven","so","fine","That","all","the","world","will","be","in","love","with","night","And","pay","no","worship","to","the","garish","sun."};
    int maxWidth = 25;

    Solution s;
    vector<string> result = s.fullJustify(words, maxWidth);

    for(auto& str : result)
    {
        cout << str << "| size: " << str.size() << "\n";
    } 

    return 0;
}