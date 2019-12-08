class Solution {
public:
    struct elem {
        int val;
        int freq;
        elem(int val_, int freq_)
        : val(val_)
        , freq(freq_) {}
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int i = 0; i < nums.size(); ++i) {
            frequency[nums[i]] += 1;
        }
        
        vector<elem> heap;
        for (auto it = frequency.begin(); it != frequency.end(); ++it) {
            heap.push_back(elem(it->first, it->second));
        }
        
        for (size_t i = heap.size() / 2 + 1; i > 0; --i) {
            siftDown(heap, i-1);
        }
        
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(deleteMax(heap).val);
        }
        return res;
    }
    
    void siftDown(vector<elem>& nums, size_t i) {
        while (2 * i + 1 < nums.size()) {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;
            size_t max_ind = left;
            if (right < nums.size() && nums[right].freq > nums[max_ind].freq) {
                max_ind = right;
            }
            if (nums[i].freq >= nums[max_ind].freq) {
                break;
            }
            swap(nums[i], nums[max_ind]);
            i = max_ind;
        }
    }
    
    elem deleteMax(vector<elem>& nums) {
        elem max = nums[0];
        nums[0] = nums[nums.size() - 1];
        nums.erase(nums.end() - 1);
        siftDown(nums, 0);
        return max;
    }
};
