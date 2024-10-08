class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {
            // If it's an opening bracket, push it onto the stack
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                st.push(s[i]);
            }
            else {
                // If we encounter a closing bracket and the stack is empty, it's invalid
                if (st.empty()) {
                    return false;
                }

                char ch = st.top();
                st.pop();

                // Check for matching pair
                if ((s[i] == ')' && ch != '(') ||
                    (s[i] == ']' && ch != '[') ||
                    (s[i] == '}' && ch != '{')) {
                    return false;
                }
            }
        }

        // If the stack is empty, all parentheses were matched; otherwise, it's invalid
        return st.empty();
    }
};
