//Optimal Approach
// TC : 0(n)
// SC : 0(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        int mis = -1;

        for(int i=0; i<n; i++){
            if(nums[abs(nums[i]) - 1] < 0) dup = abs(nums[i]);
            else nums[abs(nums[i]) - 1] *= (-1);
        }

        for(int i=0; i<n; i++){
            if(nums[i] > 0) {
                mis = i + 1;
            }
        }
        return {dup, mis};
    }
};


//Map Approach
// TC : 0(n)
// SC : 0(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        // Populating the map
        for(auto it:nums) mp[it]++;

        int dup = -1; //duplicate number
        int mis = -1; //missing number

        //Iterating over [1,n] to get the missing number
        for(int i=1; i<=n; i++){
            if(mp.find(i) == mp.end()) mis = i;
        }
        //Iterating over map to get the duplicate number
        for(auto i : mp) {
            if(i.second != 1) dup = i.first;
        }
        return {dup,mis};
    }
};





