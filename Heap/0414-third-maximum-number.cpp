//Sorting Approach
// TC : O(nlogn)
// SC : O(1)

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());

        int n = nums.size();

        return (n >= 3)? nums[n-3] : nums.back();
    }
};

//- Time complexity: O(n log n)
//- Space complexity: O(n) 
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for(auto &it : nums) st.insert(it);                    //O(nlogn) time for insertion in set, space is o(n) for n distinct elements

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &it : st) {
            pq.push(it);

            if(pq.size() > 3) pq.pop();                        //O(3) at most 3 elements can be inserted in heap, hence space is O(1) for heap
        }

        if(pq.size() < 3) {
            while( pq.size() > 1 ) pq.pop();                  //this will also run at maximum of 2 times
        }
        return pq.top();
    }
};
