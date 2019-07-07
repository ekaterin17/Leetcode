class Solution {
public:
    int projectionArea(const vector<vector<int>>& grid) {
        int area = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            int maxInCol = 0;
            int maxInRow = 0;
            for (size_t j = 0; j < grid.size(); ++j) {
                if (grid[i][j] > 0) ++area;
                maxInRow = max(maxInRow, grid[i][j]);
                maxInCol = max(maxInCol, grid[j][i]);
            }
            area += maxInRow + maxInCol;
        }
        return area;
    }
};
