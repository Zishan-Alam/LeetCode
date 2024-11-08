// - Time Complexity: O(n)
// - Space Complexity: O(n)
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> result(n);

        //finding the xorr of all the elements
        int xorr = 0;
        for(auto &it : nums) xorr ^= it;

        //finding the mask to xorr with to get the maximum k
        int mask = ((1 << maximumBit) - 1);

        for(int i=0; i<n; i++) {
            int k = xorr ^ mask;
            result[i] = k;

            xorr = xorr ^ nums[n-i-1];  // xorring with the last element and removing it
        }
        return result;
    }
};
