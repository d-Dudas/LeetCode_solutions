#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> r;
        vector<int>::iterator it = nums.begin();
        while(it + k - 1 != nums.end())
        {
            r.push_back(*max_element(it, it+k));
            it++;
        }
        return r;
    }
};

int main()
{
    Solution sol;
    vector<int> test1 = {1,3,-1,-3,5,3,6,7};

    vector<int> rez = sol.maxSlidingWindow(test1, 3);
    for(auto& val : rez) cout << val <<" ";
    cout << "\n";
}