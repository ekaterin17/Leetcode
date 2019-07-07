class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool used[rooms.size()];
        for (size_t i = 0; i < rooms.size(); ++i) {
            used[i] = false;
        }
        
        queue<int> q;
        for (size_t i = 0; i < rooms[0].size(); ++i) {
            q.push(rooms[0][i]);
        }
        used[0] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (!used[u]) {
                for (size_t i = 0; i < rooms[u].size(); ++i) {
                    q.push(rooms[u][i]);
                }
                used[u] = true;
            }
        }
        
        for (size_t i = 0; i < rooms.size(); ++i) {
            if (!used[i]) return false;
        }
        return true;
    }
};
