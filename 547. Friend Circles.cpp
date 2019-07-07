class Solution {
public:
    int findCircleNum(const vector<vector<int>>& M) {
        int res = 0;
        vector<bool> visited(M.size(), false);
        for (size_t i = 0; i < M.size(); ++i) {
            if (!visited[i]) {
                res += 1;
                dfs(i,M,visited);
            }
        }
        return res;
    }
    
    void dfs(const size_t& i, const vector<vector<int>>& M, vector<bool>& visited) {
        visited[i] = true;
        for (size_t j = 0; j < M.size(); ++j) {
            if (i != j and M[i][j] && !visited[j]) {
                dfs(j,M,visited);
            }
        }
    }
};
