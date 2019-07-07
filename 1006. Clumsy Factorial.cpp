class Solution {
public:
    int clumsy(int N) {
        int res = 0;
        int sign = 1;
        while (N > 0) {
            float temp = sign * N;
            if (N-1 > 0) temp *= float(N-1);
            if (N-2 > 0) temp /= float(N-2);
            res += int(temp);
            if (N-3 > 0) res += N-3;
            sign = -1;
            N -= 4;
        }
        return res;
    }
};
