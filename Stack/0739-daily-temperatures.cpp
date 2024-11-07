// time complexity is O(n^2) and the space complexity is O(n).
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> result(n,0);

        for(int i=0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(temp[j] > temp[i]) {
                    result[i] = j-i;
                    break;
                }
            }
        }
        return result;
    }
};
// stack approach
/*
  Time Complexity:
The time complexity of this solution is O(n), where n is the number of elements in the input vector `temp`. This is because each element is pushed and popped from the stack at most once. The outer loop iterates through each temperature, and the inner while loop processes elements in the stack, ensuring that each element is handled in constant time on average.

Space Complexity:
The space complexity is O(n) in the worst case, which occurs when the stack stores all indices of the input vector. In the best case, where temperatures are strictly decreasing, the stack may contain fewer elements, but we still consider the worst case for analysis. Additionally, the result vector also requires O(n) space to store the output.
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> result(n);

        for(int i=n-1; i>=0; i--) {

            while( !st.empty() && temp[st.top()] <= temp[i]) st.pop();

            if(st.empty()) result[i] = 0;
            else result[i] = st.top() - i;

            st.push(i);
        }
        return result;
    }
};
