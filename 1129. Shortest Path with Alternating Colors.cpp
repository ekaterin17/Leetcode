class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<pair<int, int> > > gr(n);
        for (auto& edge : red_edges) {
            gr[edge[0]].push_back({edge[1], 0});
        }
        for (auto& edge : blue_edges) {
            gr[edge[0]].push_back({edge[1], 1});
        }
        
        vector<int> dist(n, -1);
        vector<vector<bool> > used(n, vector<bool>(2, false));
        
        queue<pair<int,int> > q;
        q.push({0, 0});
        used[0][0] = true;
        q.push({0, 1});
        used[0][1] = true;
        dist[0] = 0;
        int depth = 1;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                auto cur = q.front();
                q.pop();
                for (auto u : gr[cur.first]) {
                    if (!used[u.first][u.second] && u.second != cur.second) {
                        q.push(u);
                        used[u.first][u.second] = true;
                        if (dist[u.first] == -1) {
                            dist[u.first] = depth;
                        }
                    }
                }    
            }
            ++depth;
        }
    
        return dist;
    }
};
