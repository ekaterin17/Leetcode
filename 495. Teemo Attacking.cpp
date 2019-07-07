class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(!timeSeries.size())
            return 0;
        int sum = duration;
        for(int i = 1; i < timeSeries.size(); ++i){
            if(timeSeries[i]  - timeSeries[i - 1] >= duration)
                sum += duration;
            else
                sum += timeSeries[i] - timeSeries[i - 1];
        }
        return sum;
    }
};
