// TC : 0(n) where n is the length of the string
// SC : 0(n) in the worst case when all are opening brackets
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto &ch : s) {

            if(st.empty() || ch == '(' || ch == '[' || ch == '{') st.push(ch);

            if(ch == ')') {
                if(st.top() == '(') st.pop();
                else return false;
            }
            if(ch == ']') {
                if(st.top() == '[') st.pop();
                else return false;
            }
            if(ch == '}') {
                if(st.top() == '{') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
// Cleaner code
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto &ch : s) {

            if(ch == '(') st.push(')');
            else if(ch == '[') st.push(']');
            else if(ch == '{') st.push('}');

            else if(st.empty() || st.top() != ch) return false;
            else st.pop();
        }
        return st.empty();
    }
};
