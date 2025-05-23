class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, -1);
        for(int i=0; i<s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> seen(26, false);
        stack<char> st;

        for(int i=0; i<s.length(); i++) {

            int curr = s[i] - 'a';

            if(seen[curr]) continue;

            while(!st.empty() && st.top() > s[i] && i < lastIndex[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[curr] = true;
        }
            string ans = "";
            while(!st.empty()) {
                ans += st.top();
                st.pop();
            }

            reverse(ans.begin(), ans.end());
            return ans;
    }
};
