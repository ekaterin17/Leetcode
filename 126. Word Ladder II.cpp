#include <algorithm>
#include <iostream>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

bool isCanBeTransform(const string& s1, const string& s2) {
    int count = 0;
    for (size_t i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            ++count;
        }
    }
    
    if (count == 1)
        return true;
    else
        return false;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, vector<string> > gr;
    unordered_set<string> used(wordList.begin(), wordList.end());
    if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
        wordList.push_back(beginWord);
    for (size_t i = 0; i < wordList.size(); ++i) {
        for (size_t j = i + 1; j < wordList.size(); ++j) {
            if (isCanBeTransform(wordList[i], wordList[j])) {
                gr[wordList[i]].push_back(wordList[j]);
                gr[wordList[j]].push_back(wordList[i]);
            }
        }
    }
    
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
                for (string word : gr[u.back()]) {
                    if (used.find(word) != used.end()) {
                        auto new_u = u;
                        new_u.push_back(word);
                        q.push(new_u);
                        deletedWord.insert(word);
                    }
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

int main(int argc, const char * argv[]) {
    string begin = "a";
    string end = "c";
    vector<string> words = {"a", "b", "c"};
    auto res = findLadders(begin, end, words);
    cout << "Ans";
    return 0;
}
