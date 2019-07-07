class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        vector<int> pos;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == target)
                pos.push_back(i);
        }
        return pos[rand() % pos.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
