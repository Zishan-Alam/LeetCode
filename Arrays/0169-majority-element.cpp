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
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int majority = 0;
        
        for (int n : nums) {
            if (majority == 0) {
                res = n;
            }
            
            majority += (res == n) ? 1 : -1;
        }
        
        return res;        
    }
};
