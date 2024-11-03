// Time complexity is O(n log n) 
// Space complexity is O(n).
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;             //minheap
        for(auto &it : nums) pq.push(it);

        int n = nums.size()-1;

        int i=0;
        while( !pq.empty()) {
            nums[i] = pq.top();
            pq.pop();

            i++;
        }
        return nums;
    }
};
