class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        //sorting such that the property holds of a < b < c & if this holds, then we only check a+b > c, other two are already satisfied
        sort(nums.begin(), nums.end());

        for(int i=n-3; i>=0; i--){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            if(a+b > c) return a+b+c;

        }
        return 0;
    }
};
