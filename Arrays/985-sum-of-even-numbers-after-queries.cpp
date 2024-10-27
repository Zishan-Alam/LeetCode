class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();        //size of nums vector
        int q = queries.size();     //size of query vector

        int sumEven = 0;
        vector<int> result; //to store answer

        //Step-01 : Calculating sumEven in array before operations of query
        for(auto &num : nums) {
            if(num % 2 == 0) sumEven += num;
        }

        //Step-02 : applying queries and calculating sumEven in between 
        for(int i=0; i<q; i++){
            int val = queries[i][0];
            int idx = queries[i][1];

            if(nums[idx] % 2 == 0) sumEven -= nums[idx];    //even number

            nums[idx] += val;

            if(nums[idx] % 2 == 0) sumEven += nums[idx];    //even number

            result.push_back(sumEven);
        }
        return result;
    }
};
