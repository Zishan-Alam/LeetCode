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


//constant space
//Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1;
        int count = 0;

        for(auto &it: nums) {
            if(count == 0) res = it;
            count += (res == it)? 1 : -1;
        }
        return res;
    }
};
