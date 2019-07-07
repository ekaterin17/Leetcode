class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> res;
        for (auto word : words) {
            if (match(word, pattern)) {
                res.push_back(word);
            }
        }
        return res;
    }
    
    bool match (string word, string pattern) {
        map<char, char> hash;
        map<char, char> hash2;
        for (size_t i = 0; i < word.length(); ++i) {
            if (hash.count(word[i]) == 0) {
                hash[word[i]] = pattern[i];
            }
            if (hash2.count(pattern[i]) == 0) {
                hash2[pattern[i]] = word[i];
            }
            if (hash[word[i]] != pattern[i] || hash2[pattern[i]] != word[i]) {
                return false;
            }
        }
        return true;
    }
    
    
};
