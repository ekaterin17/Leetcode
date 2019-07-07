class Solution {
private:
    static bool comp(vector<int>& nums1, vector<int>& nums2) {
        return nums1[1] < nums2[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int cur = INT_MIN;
        int res = 0;
        for (size_t i = 0; i < pairs.size(); ++i) {
            if (cur < pairs[i][0]) {
                res += 1;
                cur = pairs[i][1];
            }
        }
        return res;
    }
};
