class Solution {
public:
    int hammingDistance(int x, int y) {
        int c = x^y;
        int res = 0;
        while (c != 0) {
            if (c % 2 == 1) ++res;
            c /= 2;
        }
        return res;
    }
};
