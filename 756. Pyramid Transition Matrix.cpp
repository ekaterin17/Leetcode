class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,string> map;
        for(string s:allowed)map[s.substr(0,2)]+=s.substr(2,1);
        return helper(bottom,"",0,map);
    }
    bool helper(string bottom,string k,int i,unordered_map<string,string>& map)
    {
        int size=bottom.size();
        if(size<2)return true;
        if(i==size-1) return helper(k,"",0,map);
        else for(char c:map[bottom.substr(i,2)]) if(helper(bottom,k+c,i+1,map))return true;          
        return false;     
    }
};
