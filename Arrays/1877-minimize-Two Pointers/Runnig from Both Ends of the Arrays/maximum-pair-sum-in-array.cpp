class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //sort the vector to apply 2 pointer
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mx = INT_MIN;

        int i = 0;
        int j = nums.size() - 1;

        while(i<=j){
            int sum = nums[i] + nums[j]; //to minimize maximum pair sum, pair smallest to the largest !!
            if(sum > mx){
                mx = max(sum, mx);
            }
            //ye operation har case mai hoga!!
            i++;
            j--;
        }
        return mx;
    }
};
