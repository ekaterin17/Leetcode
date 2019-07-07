class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> sortedSquares;
        int i = 0; //negative parts
        int j = 0; //positive parts
        
        while (j < A.size() && A[j] < 0) {
            ++j;
        }
        i = j - 1;
        
        while (i >= 0 && j < A.size()) {
            if (A[i] * A[i] < A[j] * A[j] ) {
                sortedSquares.push_back(A[i] * A[i]);
                --i;
            } else {
                sortedSquares.push_back(A[j] * A[j]);
                ++j;
            }
        }
        
        while (i >= 0) {
            sortedSquares.push_back(A[i] * A[i]);
                --i;
        }
        
        while (j < A.size()) {
            sortedSquares.push_back(A[j] * A[j]);
            ++j;
        }
        return sortedSquares;
    }
};
