class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        size_t j = 0;
        for (size_t i = 0; i < pushed.size(); ++i) {
            stack.push(pushed[i]);
            while (!stack.empty() && j < popped.size() && stack.top() == popped[j]) {
                stack.pop();
                ++j;
            }
        }
        return j == popped.size();
    }
};
