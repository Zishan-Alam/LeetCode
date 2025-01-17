class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(auto it : nums) {
            mp[it]++;

            if(mp[it] > n/2) return it;
        }
        return -1;
    }
};
