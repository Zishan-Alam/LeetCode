class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;

        for(auto it : nums){
            if(mp.find(it) != mp.end()) ans += mp[it];
            mp[it]++;
        }
        return ans;
    }
};
