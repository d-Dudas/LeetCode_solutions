#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int curMax;
    bool isOk(vector<int>& nums, int& i)
    {
        if(nums[i] < curMax) return false;
        curMax = nums[i];
        return true;
    }

    int findUnsortedSubarray(vector<int>& nums) {
        int usl = 0;
        curMax = nums[0];
        int firstWrongPoz = nums.size();
        for(int i = 1; i < nums.size(); i++)
        {
            if(not isOk(nums, i))
            {
                firstWrongPoz = firstWrongPoz > i ? i - 1 : firstWrongPoz;
                usl = i - firstWrongPoz + 1;
            }
        }

        return usl;
    }
};

int main()
{
    vector<int> testArray1 = {2,6,4,8,10,9,15};
    vector<int> testArray2 = {1,2,3,4};
    vector<int> testArray3 = {1};

    int expected1 = 5;
    int expected2 = 0;
    int expected3 = 0;

    Solution sol;

    int result1 = sol.findUnsortedSubarray(testArray1);
    int result2 = sol.findUnsortedSubarray(testArray2);
    int result3 = sol.findUnsortedSubarray(testArray3);

    result1 == expected1 ? cout << "Resut 1 correct.\n" : cout << "Result 1 not correct." << result1 <<"\n";
    result2 == expected2 ? cout << "Resut 2 correct.\n" : cout << "Result 2 not correct." << result2 <<"\n";
    result3 == expected3 ? cout << "Resut 3 correct.\n" : cout << "Result 3 not correct." << result3 <<"\n";

    return 0;
}