class Solution {
public:
    vector<int> diStringMatch(string S) {
        int l = 0;
        int h = S.length();
        vector<int> res(S.length()+1);
        for (size_t i = 0; S[i] != '\0'; ++i) {
            if (S[i] == 'I') {
                res[i] = l++;
            } else {
                res[i] = h--;
            }
        }
        res[S.length()] = l;
        return res;
    }
};
