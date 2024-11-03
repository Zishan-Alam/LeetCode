// Time complexity: O(N) where N --> total number of elements in all the subarrays of the input vector `nums`
// Space complexity: O(N)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> diagonal;
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j< nums[i].size(); j++) {
                diagonal[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> result;

        for(auto vect : diagonal) {
            reverse(vect.second.begin(), vect.second.end());
            for(auto it : vect.second) result.push_back(it);
        }
        return result;
    }

};
