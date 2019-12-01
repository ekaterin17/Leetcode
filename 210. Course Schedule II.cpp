class Solution {
public:
    vector<int> used;
    vector<int> topsort;
    
    bool dfs(const vector<vector<int> >& gr, const int u) {
        used[u] = 1;
        for (size_t i = 0; i < gr[u].size(); ++i) {
            int to = gr[u][i];
            if (used[to] == 0) {
                if (dfs(gr, to)) {
                    return true;
                }
            } else if (used[to] == 1) {
                return true;
            }
        }
        used[u] = 2;
        topsort.push_back(u);
        return false;
    }
    
    vector<int> findOrder(int numCourses, const vector<vector<int>>& prerequisites) {
        used.assign(numCourses, 0);
        vector<vector<int> > gr(numCourses);
        for (const auto& courses : prerequisites) {
            gr[courses[1]].push_back(courses[0]);
        }
        
        bool cycle = false;
        for (size_t i = 0; i < gr.size(); ++i) {
            if (used[i] == 0 && dfs(gr,i)) {
                cycle = true;
            }
        }
        
        if (cycle) {
            return {};
        } else {
            reverse(topsort.begin(), topsort.end());
            return topsort;
        }
    }
};
