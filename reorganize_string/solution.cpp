#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        if(s.size() < 0) return s;

        unordered_map<char, int> freqMap;
        for(char& c : s)
        {
            freqMap[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(auto& [ch, freq] : freqMap)
        {
            maxHeap.push({freq, ch});
        }

        string res;
        while(maxHeap.size() >= 2)
        {
            auto [freq1, char1] = maxHeap.top(); maxHeap.pop();
            auto [freq2, char2] = maxHeap.top(); maxHeap.pop();

            res += char1;
            res += char2;

            if(--freq1 > 0) maxHeap.push({freq1, char1});
            if(--freq2 > 0) maxHeap.push({freq2, char2});
        }

        if(!maxHeap.empty())
        {
            auto [freq, ch] = maxHeap.top();
            if(freq > 1) return "";
            res += ch;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string input1 = "aab";
    
    cout << sol.reorganizeString(input1) << "\n";

    return 0;
}