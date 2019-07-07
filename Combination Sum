class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= target; ++i) {
            for (size_t j = 0; j < candidates.size(); ++j) {
                if (i == candidates[j]) {
                    dp[i].emplace_back();
                    dp[i].back().push_back(candidates[j]);
                } else if (i - candidates[j] > 0) {
                    if (dp[i-candidates[j]].size()) {
                        for (size_t k = 0; k < dp[i-candidates[j]].size(); ++k) {
                            if (dp[i-candidates[j]][k].back() > candidates[j]) continue;
                            dp[i].push_back(dp[i-candidates[j]][k]);
                            dp[i].back().push_back(candidates[j]);
                            
                        }
                    }
                }
            }
        }
        return dp[target];
    }
};
