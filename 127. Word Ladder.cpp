class Solution {
public:
    int ladderLength(const string& beginWord, const string& endWord, vector<string> wordList) {
        unordered_map<string, vector<string> > gr;
        unordered_map<string, bool> used;
        unordered_map<string, int> dist;
        
        wordList.push_back(beginWord);
        for (size_t i = 0; i < wordList.size(); ++i) {
            for (size_t j = i + 1; j < wordList.size(); ++j) {
                if (isCanBeTransform(wordList[i], wordList[j])) {
                    gr[wordList[i]].push_back(wordList[j]);
                    gr[wordList[j]].push_back(wordList[i]);
                }
            }
            used[wordList[i]] = false;
        }
        
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        used[beginWord] = true;
        
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            for (string word : gr[u]) {
                if (!used[word]) {
                    q.push(word);
                    dist[word] = dist[u] + 1;
                    used[word] = true;
                }
            }
        }
        
        if (dist.find(endWord) == dist.end())
            return 0;
        else
            return dist[endWord];
    }
    
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
};
