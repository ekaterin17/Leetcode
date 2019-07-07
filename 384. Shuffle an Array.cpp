class Solution {
private:
    vector<int> array;
    vector<int> originNums;
public:
    Solution(vector<int>& nums) {
        originNums.resize(nums.size());
        array.resize(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            originNums[i] = nums[i];
            array[i] = nums[i];
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return originNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (size_t i = 0; i < array.size(); ++i) {
            size_t j  = rand() % array.size();
            swap(array[i],array[j]);
        }
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
