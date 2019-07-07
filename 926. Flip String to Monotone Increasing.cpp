class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> cnts(S.size()+1,0);
        for (size_t i = 0; i < S.size(); ++i) {
            cnts[i+1] = cnts[i] + (S[i] == '1' ? 1:0);
        }
        
        int ans = INT_MAX;
        int n = cnts.size();
        for (int i = 0; i < n; ++i) {
            ans = min(ans, cnts[i] + n-1-i - (cnts[n-1] - cnts[i]));
        }
        
        return ans;
    }
};
