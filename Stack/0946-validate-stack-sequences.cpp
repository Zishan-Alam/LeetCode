// time complexity of the algorithm is O(n), where n is the number of elements
// space complexity is O(n) in the worst case
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int n = popped.size();
        int j = 0;

        for(int i=0; i<n; i++) {

            st.push(pushed[i]);

            while(!st.empty() && popped[j] == st.top()) {   // if same elements are there, then we can pop and check further
                st.pop();
                j++;
            }
        }
        return st.empty();  //true if stack is empty at last and false otherwise
    }
};
