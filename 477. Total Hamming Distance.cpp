class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
       vector<int> bit_count(32,0);
        int res=0;

        for(int i = 0;i < nums.size();i++) {
            for(int j = 0;j < 32; ++j) {
                if((1<<j)&nums[i])
                    res += (i - bit_count[j]++);
                else
                    res += bit_count[j];
            }
        }

        return res;
    }
};
