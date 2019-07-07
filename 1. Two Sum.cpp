class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indecesOfSum(2);
        bool flag = false;
        for (int i = 0; (i < nums.size() - 1) && !flag; ++i) {
            for (int j = i + 1; j < nums.size() && !flag; ++j) {
                if (nums[i] + nums[j] == target) {
                    indecesOfSum[0] = i;
                    indecesOfSum[1] = j;
                    flag = true;
                }
            }
        }
        return indecesOfSum;
    }
};
