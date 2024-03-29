class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int result = 0;
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int mid = nums[nums.size() / 2];
        for (auto num : nums) {
            result += abs(mid - num);
        }

        return result;
    }
};
