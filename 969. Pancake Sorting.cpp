class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        size_t end = A.size();
        while (end > 0) {
            size_t ind;
            for (size_t i = 0; i < end; ++i) {
                if (A[i] == end) {
                    ind = i;
                }
            }
            reverse(A.begin(), A.begin() + (ind + 1));
            reverse(A.begin(), A.begin() + end);
            res.push_back(ind+1);
            res.push_back(end);
            end--;
        }
        return res;
    }
};
