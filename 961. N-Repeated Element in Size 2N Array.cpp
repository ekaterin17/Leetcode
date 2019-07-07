class Solution {
public:
    int repeatedNTimes(const vector<int>& A) {
        map <int, int> count;
        for (size_t i = 0; i < A.size(); ++i) {
            count[A[i]] += 1;
            if (count[A[i]] > 1) {
                return A[i];
            }
        }
        return -1;
    }
};
