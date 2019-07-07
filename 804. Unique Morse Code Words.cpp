class Solution {
private:
    string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> set;
        for (size_t i = 0; i < words.size(); ++i) {
            string resStr = "";
            for (size_t j = 0; j < words[i].size(); ++j) {
                resStr += morse[words[i][j] - 'a'];
            }
            set.insert(resStr);
        }
        return set.size();
        
    }
};
