// Using Stack
// TC : 0(n) where n --> length of the string
// SC : 0(n) in the worst case
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string result = "";

        for(auto &ch : s) {

            if(ch == '*') st.pop();
            else st.push(ch);
        }
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
};
// Using String
// TC : 0(n)
// SC ; 0(1)
class Solution {
public:
    string removeStars(string s) {
        string result = "";

        for(auto &ch : s) {
            if(ch == '*') result.pop_back();
            else result += ch;
        }
        return result;
    }
};
// Using two pointer
class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        int j = 0;

        vector<char> temp(n);
        string result = "";

        for(int i=0; i<n; i++) {
            if(s[i] == '*') {
                j--;
            }
            else {
                temp[j] = s[i];
                j++;
            }
        }
        for(int i=0; i<j; i++) {
            result += temp[i];
        }
        return result;
    }
};
