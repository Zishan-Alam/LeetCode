// Using stack
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
// Using string
// time complexity of the `simplifyPath` function is O(n), where n is the length of the input string `path`
// space complexity is O(m), where m is the number of valid directory names in the simplified path. 
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        string result = "";

        stringstream ss(path);
        string token = "";

        while(getline(ss, token, '/')) {
            if(token == "" || token == ".") continue;
            if(token != "..") vec.push_back(token);
            else if(!vec.empty()) vec.pop_back();
        }

        if(vec.size() == 0) return "/";

        for(auto token : vec) {
            result = result + "/" + token;
        }
        return result;
    }
};
