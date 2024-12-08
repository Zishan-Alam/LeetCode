class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        set<int> set;

        int i = 0;
        int j = 0;

        while(j < n) {

            if(abs(i-j) > k) {
                set.erase(nums[i]);
                i++;
            }

            if(set.find(nums[j]) != set.end()) return true;
            set.insert(nums[j]);
            j++;
        }
        return false;
    }
};
