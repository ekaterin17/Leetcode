class Solution {
private:
    std::vector<vector<int>> paths;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        std::vector<int> path;
        bool used[15] = {0};
        dfs(graph,0,path,used);
        return paths;
    }
    
    void dfs(vector<vector<int>>& graph, int curNode, std::vector<int> path, bool used[]) {
        used[curNode] = true;
        path.push_back(curNode);
        if (curNode == graph.size()-1) {
            paths.push_back(path);
        } else {
            for (size_t i = 0; i < graph[curNode].size(); ++i) {
                if (!used[graph[curNode][i]]) {
                    dfs(graph,graph[curNode][i],path,used);
                }
            }
        }
        used[curNode] = false;
    }
};
