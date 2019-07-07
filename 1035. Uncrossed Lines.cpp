class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<int> dp(B.size()+1, 0);

        for (int i=0; i<A.size(); i++) {
            int prev = 0;
            for (int j=0; j<B.size(); j++) {
                int curr = dp[j+1];
                if (A[i] == B[j])
                    dp[j+1] = 1 + prev;
                else
                    dp[j+1] = max(dp[j], dp[j+1]);
                prev = curr;
            }
        }
        
        return dp.back();
    }
};
