// This solution is not correct.
// I refuse to continue working on this because the description is too ambigous
// Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool isThreeEqual(vector<int>& nums, const int& startIndex)
    {
        return nums[startIndex] == nums[startIndex + 1] and nums[startIndex] == nums[startIndex + 2] ? true : false;
    }

    bool isThreeConsecutive(vector<int>& nums, const int& startIndex)
    {
        return nums[startIndex] + 1 == nums[startIndex + 1] and nums[startIndex + 1] + 1 == nums[startIndex + 2] ? true : false;
    }

    bool isValidSubArray(vector<int>& nums, int startIndex)
    {
        if(isThreeEqual(nums, startIndex) and isThreeConsecutive(nums, startIndex + 2)) return true;
        if(isThreeConsecutive(nums, startIndex) and isThreeEqual(nums, startIndex + 2)) return true;
        return false;
    }

    bool validPartition(vector<int>& nums) {
        if(nums.size() < 5) return false;
        for(int i = 0; i <= nums.size() - 5; i++)
        {
            if(isValidSubArray(nums, i)) return true;
        }
        return false;
    }
};

int main()
{
    vector<int> testArray1 = {4,4,4,5,6};
    vector<int> testArray2 = {1,1,1,2};

    Solution sol;

    sol.validPartition(testArray1) == true ? cout << "Test array 1 validated\n" : cout << "\033[0;31mError: \033[0;37mTest Array 1 not validated\n";
    sol.validPartition(testArray2) == false ? cout << "Test array 2 not validated\n" : cout << "\033[0;31mError: \033[0;37mTest Array 2 validated\n";
    
    return 0;
}