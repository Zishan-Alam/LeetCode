//Map Approach
// TC : 0(n)
// SC : 0(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(auto it : nums) mp[it]++;
        for(auto it : mp) if(it.second != 1) return true;
        return false;
    }
};


//Sorting Approach
// TC : 0(nlogn)
// SC : 0(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};

//Hash Set Approach
// TC : 0(n)
// SC : 0(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> st;
        for(auto it : nums) st.insert(it);

        if(nums.size() != st.size()) return true;
        return false;
    }
};
