class Solution {
public:
     int maxChunksToSorted(vector<int>& v) {
        int min_value, max_value, n = 1;
        auto k = v.begin();
        for (auto it = v.begin(); it != v.end() - 1; it ++)
        {
            min_value = *(min_element(it + 1, v.end()));
            max_value = *(max_element(k, it + 1));
            if (max_value <= min_value)
            {
                n ++;
                k = it;
            }
        }
        return n;
    }
};
