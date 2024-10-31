// Heap 
// Time complexity is O(n log n) 
// Space complexity is O(n).
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &it : nums) pq.push(it);

        vector<int> res;

        while( !pq.empty() ) {
            int alice = pq.top(); pq.pop();
            int bob   = pq.top(); pq.pop();

            res.push_back(bob);
            res.push_back(alice);
        }
        return res;
        
    }
};

// Sorting
// TC : O(n logn)
// SC : O(n)
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;

        for(int i=0; i<n-1; i+=2) {
            res.push_back(nums[i+1]);
            res.push_back(nums[i]);
        }
        return res;
    }
};
