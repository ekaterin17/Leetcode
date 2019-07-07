class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        int i = 0, j = 0;
        int mx = 0, cnt = 0;
        
        while(j < n) {
            while(cnt > k) {
                cnt -= (a[i] == 0 ? 1 : 0);
                ++i;
            }
            mx = max(mx, j-i);
            
            cnt += (a[j++] == 0 ? 1 : 0);
        }
        while(cnt > k) {
            cnt -= (a[i] == 0 ? 1 : 0);
            ++i;
        }
        mx = max(mx, j-i);
        
        return mx;
    }
};
