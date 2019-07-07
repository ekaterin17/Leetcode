class Solution {
public:
    struct Node {
        bool root;
        unordered_map<char,Node*> child;
        Node(Node* parent = NULL, char c = 'a') : root(false) {
            if (parent) parent->child[c] = this;
        }
        Node* get(char c, bool create = false) { 
            auto iter = this->child.find(c);
            if (iter != child.end()) return iter->second;
            else if (create) return new Node(this, c);
            return NULL;
        }
    };
    
    Node root;

    string replaceWords(vector<string>& dict, string sentence) {
        // Setup trie
        for (auto& r : dict) {
            Node *cur = &root;
            for (auto c : r) cur = cur->get(c, true);
            cur->root = true;
        }
        
        // Parse sentence, process output 
        stringstream input(sentence);
        string word, output;
        
        while (getline(input, word, ' ')) {
            Node *cur = &root;
            int i;
            
            for (i = 0; i < word.length() && cur && !cur->root; ++i) 
                cur = cur->get(word[i]);
        
            if (output.length())  output += ' ';
            output += (!cur || !cur->root) ? word : word.substr(0, i);
        }
        return output;
    }
};
