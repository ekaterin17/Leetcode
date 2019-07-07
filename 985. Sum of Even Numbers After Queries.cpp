class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, const vector<vector<int>>& queries) {
        vector<int> res;
        int sum = 0;
        for (size_t i = 0; i < A.size(); ++i) {
            if (A[i] % 2 == 0) sum += A[i];
        }
        for (size_t i = 0; i < queries.size(); ++i) {
            size_t ind = queries[i][1];
            if (A[ind] % 2 == 0) {
                sum -= A[ind];
            }
            A[ind] += queries[i][0];
            if (A[ind] % 2 == 0) {
                sum += A[ind];
            }
            res.push_back(sum);
        }
        return res;
    }
};
