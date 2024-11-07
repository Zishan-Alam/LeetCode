// without using lambda
class Solution {
public:

    int operate(int a, int b, string token) {
        if(token == "+") return a+b;
        if(token == "-") return a-b;
        if(token == "*") return a*b;
        if(token == "/") return a/b;

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto &token : tokens) {

            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = operate(a, b, token);
                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

// with lambda
class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        unordered_map<string, function<int (int, int)> > mp = {
            {"+", [](int a, int b) {return a+b;} },
            {"-", [](int a, int b) {return a-b;} },
            {"*", [](int a, int b) {return a*b;} },
            {"/", [](int a, int b) {return a/b;} }
        };

        for(auto &token : tokens) {

            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = mp[token] (a, b);
                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};



