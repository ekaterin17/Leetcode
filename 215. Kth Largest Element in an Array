class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Построим кучу на максимуме
        for (size_t i = nums.size() / 2 + 1; i > 0; --i) {
            siftDown(nums, i-1);
        }
        
        int res;
        for (int i = 0; i < k; ++i) {
            res = deleteMax(nums);
        }
        return res;
    }
    
    void siftDown(vector<int>& nums, size_t i) {
        while (2 * i + 1 < nums.size()) {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;
            size_t max_ind = left;
            if (right < nums.size() && nums[right] > nums[max_ind]) {
                max_ind = right;
            }
            if (nums[i] >= nums[max_ind]) {
                break;
            }
            swap(nums[i], nums[max_ind]);
            i = max_ind;
        }
    }
    
    int deleteMax(vector<int>& nums) {
        int max = nums[0];
        nums[0] = nums[nums.size() - 1];
        nums.erase(nums.end() - 1);
        siftDown(nums, 0);
        return max;
    }
};
