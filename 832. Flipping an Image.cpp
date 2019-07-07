class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (size_t i = 0; i < A.size(); ++i) {
            for(size_t j = 0; j < (A[i].size() + 1)/2; ++j) {
                int tmp = A[i][A[i].size() - j - 1];
                A[i][A[i].size() - j - 1] = A[i][j] ^ 1;
                A[i][j] = tmp ^ 1;
            }
        }
        return A;
    }
};
