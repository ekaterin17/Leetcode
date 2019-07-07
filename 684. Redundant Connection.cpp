class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>  unionFind(edges.size()+1,-1);
        for(auto iter=edges.begin();iter!=edges.end();++iter)
        {
            int p0=findParent(unionFind,(*iter)[0]);
            int p1=findParent(unionFind,(*iter)[1]);
            if(p0==p1)
            {
                if(p0==-1)
                    unionFind[(*iter)[0]]=(*iter)[1];
                else
                    return *iter;
            }
            else
                unionFind[p0]=p1;  
        }
        return vector<int>{};   
    }
    
    //when u can use loop,no recursion
    int findParent(vector<int> & unionFind,int index)
    {
        while(unionFind[index]!=-1)
            index=unionFind[index];
        return index;
    }
};
