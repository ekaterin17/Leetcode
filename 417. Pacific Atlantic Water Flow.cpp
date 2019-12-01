class Solution {
public:
    vector<vector<bool> > isPacific;
    vector<vector<bool> > isAtlantic;
    
    bool inOcean(const vector<vector<bool> >& isOcean, int cur_x, int cur_y) {
        if ( cur_x < 0 || cur_y < 0 || 
            cur_x >= isOcean.size() || cur_y >= isOcean[0].size() ||
            isOcean[cur_x][cur_y]) {
            return false;
        }
        return true;
    }
    
    void dfs(const vector<vector<int> >& matrix, vector<vector<bool> >& isOcean, int cur_x, int cur_y, int from_height) {
        if (!inOcean(isOcean, cur_x, cur_y)) {
            return;
        }
        
        if (matrix[cur_x][cur_y] < from_height) {
            return;
        }
        
        isOcean[cur_x][cur_y] = true;
        int cur_height = matrix[cur_x][cur_y];
        
        dfs(matrix, isOcean, cur_x + 1, cur_y , cur_height);
        dfs(matrix, isOcean, cur_x, cur_y - 1 , cur_height);
        dfs(matrix, isOcean, cur_x - 1, cur_y , cur_height);
        dfs(matrix, isOcean, cur_x, cur_y + 1, cur_height);
    }
    
    vector<vector<int>> pacificAtlantic(const vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};   
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        isPacific.assign(m, vector<bool>(n, false));
        isAtlantic.assign(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; ++i) {
            dfs(matrix, isPacific, i, 0, 0);
            dfs(matrix, isAtlantic, i, n-1, 0);
        }
        
        for(int i = 0; i < n; ++i) {
            dfs(matrix, isPacific, 0, i, 0);
            dfs(matrix, isAtlantic, m-1, i, 0);
        }
        
        vector<vector<int> > path;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isPacific[i][j] && isAtlantic[i][j]) {
                    path.push_back({i,j});
                }
            }
        }
        
        return path;
    }
};
