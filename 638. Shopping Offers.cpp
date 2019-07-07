class Solution {
public:
    map<vector<int>, int> m;
    
    int eval(vector<int>& price, vector<int>& needs){
        int sum=0;
        for(int i=0; i<price.size(); i++) sum += price[i]*needs[i];
        return sum;
    }
    
    bool check(vector<int>& needs){
        for(int i=0; i<needs.size(); i++) if(needs[i]>0) return false;
        return true;
    }
    
    bool apply(vector<int> &v, vector<int>& needs){
        for(int i=0; i<needs.size(); i++) if(v[i]>needs[i]) return false;
        return true;
    }
    
    vector<int> f(vector<int> &v, vector<int> needs){
        for(int i=0; i<needs.size(); i++) needs[i] -= v[i];
        return needs;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        if(m.find(needs) != m.end()) return m[needs];
        if(check(needs)) return m[needs] = 0;
        
        int temp = eval(price, needs);

        for(int i=0; i<special.size(); i++){

            if(apply(special[i], needs)){
                vector<int> v = f(special[i], needs);
                temp = min(temp, special[i][special[i].size()-1] + shoppingOffers(price, special, v));
            }
        }
        return m[needs] = temp;
    }
};
