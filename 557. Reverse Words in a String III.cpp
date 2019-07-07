class Solution {
public:
    string reverseWords(const string s) {
        size_t i = 0;
        string resString = "";
        string word = "";
        while (i < s.size()) {
            if (s[i] == ' ') {
                resString += word + ' ';
                word = "";
            } else {
                word = s[i] + word;
            }
            ++i;      
        }
        if (word != "") {
            resString += word;
        }
        return resString;
    }
};
