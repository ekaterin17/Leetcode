class Solution {
public:
    int subtractProductAndSum(int n) {
        long long sum = 0;
        long long product = 1;
        while (n > 0) {
            int lastDigit = n % 10;
            n /= 10;
            sum += lastDigit;
            product *= lastDigit;
        }
        return product - sum;
    }
};
