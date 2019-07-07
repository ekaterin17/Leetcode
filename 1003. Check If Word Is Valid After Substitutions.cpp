class Solution {
public:
    bool isValid(string S) {
        if (S.length() < 3) {
            return false;
        }
        
        stack<string> stk;
        int n = S.length();
        for (int i = 0; i < n; i++) {
		    /* start of new token */
            if (S[i] == 'a') {
                stk.push ("a");
                continue;
            }
            
			/* 'b' or 'c' */
            if (stk.empty()) {
                return false;
            }
            
            stk.top().push_back(S[i]);
            if (stk.top().length() == 3) {
			    /* len = 3 is not always valid, say "acb" */
                if (stk.top() != "abc") {
                    return false;
                }
                
                stk.pop();
            }
        }
        
        return stk.empty();
    }
};
