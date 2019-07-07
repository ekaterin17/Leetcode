class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = 1 << nums.size();
        vector<vector<int>> res(sz);
        for (int mask = 0; mask < sz; mask++) {
            for (int i = 0; i < nums.size(); i++) {
                //checking if bit is set
                if ((mask >> i) & 0x1)
                    res[mask].push_back(nums[i]);
            }
        }
        return res;
    }
};
