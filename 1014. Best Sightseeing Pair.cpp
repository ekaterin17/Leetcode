class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0;
        int max1 = 0;
        for (int i = 0; i < A.size(); ++i) {
            res = max(res, max1 + A[i] - i);
            max1 = max(max1, A[i] + i);
        }
        return res;
    }
};
