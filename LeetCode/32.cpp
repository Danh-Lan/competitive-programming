// https://leetcode.com/problems/longest-valid-parentheses/description/

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;

        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (!st.empty()) {
                    ans = max(ans, i - st.top());
                } else {
                    st.push(i);
                }
            }
        }

        return ans;
    }
};