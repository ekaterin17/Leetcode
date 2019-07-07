class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> skylineX(grid.size());
        vector<int> skylineY(grid[0].size());
        
        for (int i = 0; i < skylineX.size(); ++i) {
            skylineX[i] = -1;
        }
        
        for (int i = 0; i < skylineY.size(); ++i) {
            skylineY[i] = -1;
        }
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                skylineX[i] = max(skylineX[i], grid[i][j]);
                skylineY[j] = max(skylineY[j], grid[i][j]);
            }
        }
        
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                res += min(skylineX[i], skylineY[j]) - grid[i][j];
            }
        }
        
        return res;
    }
};
