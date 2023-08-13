#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        std::vector<int> previous(n, 0);
        std::vector<int> current(n, 0);
        previous[0] = 1;
        
        for (int i = 0; i < m; i++) {
            current[0] = obstacleGrid[i][0] == 1 ? 0 : previous[0];
            for (int j = 1; j < n; j++) {
                current[j] = obstacleGrid[i][j] == 1 ? 0 : current[j-1] + previous[j];
            }
            previous = current;
        }
        
        return previous[n-1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid1 = {{0,0,0}, {0,1,0}, {0,0,0}};
    vector<vector<int>> grid2 = {{0,1}, {0,0}};
    
    cout << sol.uniquePathsWithObstacles(grid1) << "\n";

    return 0;
}
