class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m = q, n = p;
        while (m % 2 == 0 && n % 2 == 0) {
            m = m / 2;
            n = n / 2;
        }

        if (m % 2 == 0 && n % 2 == 1) {
            return 0;
        } else if (m % 2 == 1 && n % 2 == 0) {
            return 2;
        } else if (m % 2 == 1 && n % 2 == 1) {
            return 1;
        }
        
        return -1;
    }
};
