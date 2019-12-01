class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> used(wordList.begin(), wordList.end());
    
        queue<vector<string> > q;
        q.push({beginWord});
        used.erase(beginWord);
        vector<vector<string> > ans;
        bool hasPaths = false;
        while (!q.empty()) {
            size_t cur_level = q.size();
            unordered_set<string> deletedWord;
            
            for (size_t i = 0; i < cur_level; ++i) {
                vector<string> u = q.front();
                q.pop();
                if (u.back() == endWord) {
                    hasPaths = true;
                    ans.push_back(u);
                } else {
                    string word = u.back();
                    for (size_t i = 0; i < word.size(); ++i) {
                        char origin_char = word[i];
                        for (char ch = 'a'; ch <= 'z'; ++ch) {
                            if (origin_char == ch) {
                                continue;
                            }
                            word[i] = ch;
                            if (used.find(word) != used.end()) {
                                q.push(u);
                                q.back().push_back(word);
                                deletedWord.insert(word);
                            }
                        }
                        word[i] = origin_char;
                    }
                }
            }
        
            if (hasPaths) {
                break;
            }

            for (auto& word : deletedWord) {
                used.erase(word);
            }
        }
    
    return ans;
    }
    
    bool isCanBeTransform(const string& s1, const string& s2) {
        bool flag = false;
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (flag) {
                    return false;
                } else {
                    flag = true;
                }
            }
        }
        
        return true;
    }
};
