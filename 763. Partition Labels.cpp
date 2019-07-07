class Solution {
public:
    vector<int> partitionLabels(const string& S) {
        size_t start = 0;
        size_t end = 0; 
        map <char, size_t> letterPos;
        for (size_t i = 0; i < S.size(); ++i) {
            letterPos[S[i]] = i;
        }
        vector<int> res;
        for (size_t i = 0; i < S.size(); ++i) {
            end = max(end, letterPos[S[i]]);
            if (end == i) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
