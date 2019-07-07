class Solution {
public:
    vector<string> parenthesis;
    
    vector<string> generateParenthesis(int n) {
        getParenthesis(n, 0, 0, "");
        return parenthesis;
    }
    
    void getParenthesis(int n, int open, int close, string str) {
        if (str.length() == 2*n) {
            parenthesis.push_back(str);
            return;
        }
        
        if (open < n) {
            getParenthesis(n,open+1,close, str + "(");
        }
            
        if (close < open) {
            getParenthesis(n,open, close+1, str + ")");
        }
    }
};
