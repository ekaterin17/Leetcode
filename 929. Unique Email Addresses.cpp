class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> names;
        for (auto& email: emails) {
            string local = "";
            string reset = "";
            int i = 0;
            for (; email[i] != '@'; ++i) {
                local += email[i];
            }
            local += '\0';
            ++i;
            for (; email[i] != '\0'; ++i) {
                reset += email[i];
            }
            i = 0;
            string local2 = "";
            for (; local[i] != '+' && local[i] != '\0'; ++i) {
                if (local[i] != '.') local2 += local[i];
            }
            local2 += '\0';
            names.insert(local2 + reset);
        }
        
        return names.size();
    }
};
