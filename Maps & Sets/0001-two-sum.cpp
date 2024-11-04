// Brute Force
// TC : 0(n*n)
// SC : 0(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[j] == target - nums[i]) return {i,j};
            }
        }
        return {};
    }
};

// Optimal Approach
// TC : 0(n);
// SC : 0(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) mp[nums[i]] = i;

        for(int i=0; i<n; i++) {
            int comp = target - nums[i];
            if(mp.find(comp) != mp.end() && mp[comp] != i) return {i, mp[comp]};
        }

        return {};
    }
};
