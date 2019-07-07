class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (size_t i = 0; i < nums.size(); ++i) {
            size_t index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = - nums[index];
            } else {
                res.push_back(index+1);
            }
        }
        return res;
    }
};
