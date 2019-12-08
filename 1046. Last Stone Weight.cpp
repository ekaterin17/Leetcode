class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        for (size_t i = stones.size() / 2 + 1; i > 0; --i) {
            siftDown(stones, i-1);
        }
        
        while (stones.size() >= 2) {
            int x = deleteMax(stones);
            int y = deleteMax(stones);            
            if (x != y) {
                stones.push_back(x - y);
                siftUp(stones, stones.size() - 1);
            }
        }
        if (stones.empty()) {
            return 0;
        } else {
            return stones[0];
        }
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
    
    void siftUp(vector<int>& nums, size_t i) {
        size_t par = (i - 1) / 2;
        while (i > 0 && nums[par] < nums[i]) {
            swap(nums[par], nums[i]);
            i = par;
            par = (i - 1) / 2;
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
