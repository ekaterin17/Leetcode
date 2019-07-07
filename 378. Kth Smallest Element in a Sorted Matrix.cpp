class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> queue;
        int n = matrix.size();
        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < n; ++j)
                queue.push(matrix[i][j]);
        
        n = queue.size();
        while (n - k > 0) {
            queue.pop();
            --n;
        }
        return queue.top();
    }
};
