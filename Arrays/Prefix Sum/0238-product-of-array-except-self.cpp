class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //approach here is product of array except self = 
        //product of array except self of left(pre) * product of array except self of right(suf)
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        vector<int> ans(n);

        //calculating prefix product except self
        pre[0] = 1;
        int product = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = product;
            product = product*nums[i];
        }
        //calculating suffix product except self
        suf[n-1] = 1;
        product = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suf[i] = product;
            product = product*nums[i];
        }
        //calculating ans array
        for(int i=0; i<n; i++){
            ans[i] = pre[i]*suf[i];
        }
        return ans;
        
    }
};
