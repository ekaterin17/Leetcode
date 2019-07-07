class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        for (size_t i = 0; i < ghosts.size(); ++i) {
            for (size_t j = 0; j < 2; ++j) {
                if (abs(ghosts[i][0]-target[0]) + abs(ghosts[i][1]-target[1]) <= abs(target[0]) + abs(target[1]))
                    return false;
            }
        }
        return true;
    }
};
