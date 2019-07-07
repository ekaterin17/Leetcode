class Solution {
public:
    int numberOfArithmeticSlices(const vector<int>& A) {
        int cnt = 0;
        vector<int> dp = {0,0};
        for (size_t i = 2; i < A.size(); ++i) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp.push_back(dp[i-1] + 1);
                cnt += dp[i];
            } else {
                dp.push_back(0);
            }
        }
        return cnt;
    }
};
