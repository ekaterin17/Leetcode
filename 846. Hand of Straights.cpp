class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> counts;
        for (size_t i = 0; i < hand.size(); ++i) {
            counts[hand[i]] += 1;
        }
        while (!counts.empty()) {
            if (counts.size() < W) return false;
            int prevCard = -1;
            int cnt = 0;
            for (auto it = counts.begin(); cnt < W && it != counts.end(); ++it) {
                if (prevCard != -1 && prevCard + 1 != it->first) return false;
                it->second -= 1;
                prevCard = it->first;
                if (it->second == 0) counts.erase(it);
                ++cnt;
            }
        }
        return true;
    }
};
