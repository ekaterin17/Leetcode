class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> sum1;
        for (int i = 0; i < A.size(); ++i){
            for (int j = 0; j < B.size(); ++j){
                sum1.push_back(A[i] + B[j]);
            }
        }
        
        vector<int> sum2;
        for (int i = 0; i < C.size(); ++i){
            for (int j = 0; j < D.size(); ++j){
                sum2.push_back(C[i] + D[j]);
            }
        }
        sort(sum2.begin(), sum2.end());
        
        int cnt = 0;
        for (int i = 0; i < sum1.size(); ++i){
            int target = -sum1[i];
            cnt += upper_bound(sum2.begin(), sum2.end(), target) - 
                lower_bound(sum2.begin(), sum2.end(), target);
        }
        return cnt;
    }
};
