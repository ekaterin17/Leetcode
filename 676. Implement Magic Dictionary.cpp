class MagicDictionary {
private:
    unordered_set<string> magicDict;
public:
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        int n = dict.size();
        for(int i = 0 ; i < n ; i++){
            magicDict.insert(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        string temp = word;
        for(int i = 0 ; i < temp.size() ; i++){
            for(int j = 0 ; j < 26 ; j++){
                temp[i] = j+'a';
                if(temp != word && magicDict.count(temp) > 0){
                    return true;
                }
            }
            
            temp = word;
        }
        
        return false;
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
