class Solution {
public:
    int minAddToMakeValid(string S) {
        int balance = 0;
        int ans = 0;
        for (size_t i = 0; i < S.length(); ++i) {
            if (S[i] == '(')
                ++balance;
            else if (S[i] == ')' && balance)
                --balance;
            else
                ++ans;
        }
        return ans + balance;
    }
};
