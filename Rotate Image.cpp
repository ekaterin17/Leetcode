class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 0; row <= (int)(0.5 * (double)n - 1); row++) {
            for(int col = row; col < n - 1 - row; col++){        
                int i1 = row, j1 = col;
                int i2 = col, j2 = n - 1 - row;
                int i3 = n - 1 - row, j3 = n - 1 - col;
                int i4 = n - 1 - col, j4 = row;
                
                int temp = matrix[i1][j1];
                swap(temp, matrix[i2][j2]);
                swap(temp, matrix[i3][j3]);
                swap(temp, matrix[i4][j4]);
                swap(temp, matrix[i1][j1]);
            }
        }
    }
};
