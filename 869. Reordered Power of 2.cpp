class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int one = count(N);
        for(int i = 0; i < 32; ++i){
            if(count(0x1 << i) == one)
                return true;
        }
        
        return false;
    }
    
    int count(int num) {
        int cnt = 0;
        while(num){
            cnt += pow(10, num % 10);
            num /= 10;
        }
        return cnt;
    }
};
