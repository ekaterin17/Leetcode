class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> primes = {2,3,5};
        vector<long long> nums = {1};
        unordered_set<long long> s;
        s.insert(1);
        long long res = 0;
        long long cur = 1;
        while (cur <= n) {
            res = deleteMin(nums);
            for (long long p : primes) {
                if (s.count(res * p) == 0) {
                    insert(nums, res * p);
                    s.insert(res * p);
                }
            }
            ++cur;
        }
        return res;
    }
    
    void siftDown(vector<long long>& nums, size_t i) {
        while (2 * i + 1 < nums.size()) {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;
            size_t max_ind = left;
            if (right < nums.size() && nums[right] < nums[max_ind]) {
                max_ind = right;
            }
            if (nums[i] <= nums[max_ind]) {
                break;
            }
            swap(nums[i], nums[max_ind]);
            i = max_ind;
        }
    }
    
    void siftUp(vector<long long>& nums, size_t i) {
        size_t par = (i - 1) / 2;
        while (i > 0 && nums[par] > nums[i]) {
            swap(nums[par], nums[i]);
            i = par;
            par = (i - 1) / 2;
        }
    }
    
    int deleteMin(vector<long long>& nums) {
        long long min = nums[0];
        nums[0] = nums[nums.size() - 1];
        nums.erase(nums.end() - 1);
        siftDown(nums, 0);
        return min;
    }
    
    void insert(vector<long long>& nums, long long val) {
        nums.push_back(val);
        siftUp(nums, nums.size() - 1);
    }
};
