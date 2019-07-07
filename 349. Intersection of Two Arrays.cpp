class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> numsSet1;
        set<int> numsSet2;
        vector <int> intersection;
        for (auto x : nums1) {
            numsSet1.insert(x);
        }
        for (auto x : nums2) {
            numsSet2.insert(x);
        }
        auto it1 = numsSet1.begin();
        auto it2 = numsSet2.begin();
        while (it1 != numsSet1.end() && it2 != numsSet2.end()) {
            if (*it1 == *it2) {
                intersection.push_back(*it1);
                ++it1;
                ++it2;
            } else if (*it1 < *it2) {
                ++it1;
            } else {
                ++it2;
            }
        }
        return intersection;
    }
};
