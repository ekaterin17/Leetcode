class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, balance = 0;
        for (size_t i = 0; i < S.length(); ++i) {
            if (S[i] == '(') {
               balance += 1; 
            } else {
               balance -= 1;
                if (S[i-1] == '(') {
                    res += 1<<balance;
                }
            }
        }
        return res;
    }
};
