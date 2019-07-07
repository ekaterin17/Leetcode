class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        bool right = true, left = false, up = false, down = false;
        int rightWall = c0+1, leftWall = c0-1, topWall = r0-1, bottomWall = r0+1;
        bool add = true;
        while (res.size() < R*C) {
            if (0 <= r0 && r0 < R && 0 <= c0 && c0 < C && add) {
                vector<int> point;
                point.push_back(r0);
                point.push_back(c0);
                res.push_back(point);
            }
            if (right) {
                if (c0 == rightWall) {
                    right = false;
                    down = true;
                    rightWall += 1;
                    add = false;
                } else {
                    c0++;
                    add = true;
                }
            }
            if (down) {
                if (r0 == bottomWall) {
                    down = false;
                    left = true;
                    bottomWall += 1;
                    add = false;
                } else {
                    r0++;
                    add = true;
                }
            }
            if (left) {
                if (c0 == leftWall) {
                    left = false;
                    up = true;
                    leftWall -= 1;
                    add = false;
                } else {
                    c0--;
                    add = true;
                }
            }
            if (up) {
                if (r0 == topWall) {
                    up = false;
                    right = true;
                    topWall -= 1;
                    add = false;
                } else {
                    r0--;
                    add = true;
                }
            }
        }
        return res;
    }
};
