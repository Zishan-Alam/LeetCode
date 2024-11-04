// Map Approach
// Time complexity is O(n) 
// Space complexity is O(n).
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(auto it : nums) mp[it]++;

        for(auto it : mp) if(it.second > 1) return true;

        return false;
    }
};

// Sorting Approach
// Time complexity is O(nlogn) 
// Space complexity is O(1).

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-1; i++) {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};
