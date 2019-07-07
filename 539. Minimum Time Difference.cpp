class Solution {
public:
    int getMinutes(string a) {
        int pos1 = a[0];
        int pos2 = a[1];
        int pos3 = a[3];
        int pos4 = a[4];
        return ((a[0]-'0') * 10 + a[1]-'0') * 60 + ((a[3]-'0') * 10 + a[4]-'0');
    }
    
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int len = timePoints.size();
        int res = INT_MAX;
        for (int i = 0; i < len - 1; ++ i)
        {
            int diff = getMinutes(timePoints[i+1]) - getMinutes(timePoints[i]);
            if (diff < res)
                res = diff;
        }
        int tmp = 1440 + getMinutes(timePoints[0]) - getMinutes(timePoints[len-1]);
        return min(res, tmp);
    }
};
