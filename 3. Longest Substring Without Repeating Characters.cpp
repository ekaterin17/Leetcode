class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        unordered_set<char> chars;
        int ans = 0;
        for (size_t i = 0, j = 0; j < s.size(); ++j) {
            if (chars.find(s[j]) == chars.end()) {
                chars.insert(s[j]);
            } else {
                while (i < j && chars.count(s[j])) {
                    chars.erase(s[i++]);
                }
                chars.insert(s[j]);
            }
            ans=max(ans, int(j - i + 1));
        }
        return ans;
    }
};
