// TC : 0(n)
// SC : 0(n)
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        string result = "";
        int n = s.length();

        for(int i=0; i<n; i++) {

            if(st.empty() || st.top() != s[i]) st.push(s[i]);
            else st.pop();

        }

        while( !st.empty() ) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
