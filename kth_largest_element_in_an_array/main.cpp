#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums.at(nums.size() - k);
    }
};

int main()
{
    vector<int> test1 = {3,2,1,5,6,4};
    Solution sol;
    cout << sol.findKthLargest(test1, 2) << "\n";

    return 0;
}