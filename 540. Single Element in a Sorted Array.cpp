class Solution {
public:
    int singleNonDuplicate(const vector<int>& nums) {
        long long sum = nums[0];
        long long sum2 = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            if (nums[i] != nums[i-1]) {
                sum2 += nums[i];
            }
        
        }
        return 2*sum2 - sum;
    }
};
