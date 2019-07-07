class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.size() == 0)    return 0;
        
        unordered_map<int, int> mp;
        for (auto a: answers) mp[a]++;
        
        int res = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            res += (1 + it->first) * (1 + (it->second - 1) / (1 + it->first));
        }
        
        return res;
    }
};
