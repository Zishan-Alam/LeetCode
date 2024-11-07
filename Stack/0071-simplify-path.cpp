// time complexity of the `simplifyPath` function is O(N), where N is the length of the input string `path`. 
// space complexity is also O(N) in the worst case.
class Solution {
public:
    string simplifyPath(string path) {
        //tokenizing the string
        stringstream ss(path);
        string token = "";

        stack<string> st;
        string result = "";

        while(getline(ss, token, '/')) {    //delimiter is '/'
            if(token == "" || token == ".") continue;
            if(token != "..") st.push(token);
            else if(!st.empty()) st.pop();
        }

        if(st.empty()) return "/";

        while(!st.empty()) {
            result = "/" + st.top() + result;       //reversing the result by adding result at last
            st.pop();
        }
        return result;
    }
};
