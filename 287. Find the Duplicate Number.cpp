class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> seen;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (seen.find(nums[i]) != seen.end()) {
                return nums[i];
            }
            seen.insert(nums[i]);
        }
        return 0;
    }
};
