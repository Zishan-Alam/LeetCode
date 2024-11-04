// time complexity is O(n + m + k), where n --> nums1.size, m --> nums2.size, k --> number pf unique elements in the set
// space complexity is O(n + m) in the worst case.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //map for first array
        unordered_map<int,int> mp;
        for(auto it : nums1) mp[it]++;

        //set for second array to remove duplicates
        unordered_set<int> st;
        for(auto it : nums2) if( mp.find(it) != mp.end() ) st.insert(it);

        //vector to return the result
        vector<int> result;
        for(auto it : st) result.push_back(it);

        return result;
    }
};
