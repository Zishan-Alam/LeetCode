// Time complexity is O(n) 
// Space complexity is O(k), k --> number of unique non-zero elements.
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st;
        for(auto it : nums) if(it != 0) st.insert(it);
        return st.size();
    }
};
