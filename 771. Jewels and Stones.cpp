class Solution {
public:
    bool findStonesInJewels(string J, char s) {
        for (int i = 0; i < J.size(); ++i) {
            if (s == J[i]) {
                return true;
            }
        }
        return false;
    }
    
    int numJewelsInStones(string J, string S) {
        int cnt = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (findStonesInJewels(J,S[i])) {
                ++cnt;
            }
        }
        return cnt;
    }
};
