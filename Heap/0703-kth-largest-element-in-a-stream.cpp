//Time Complexity: O(n log k) for the constructor, O(log k) for each `add` call.
//Space Complexity: O(k).
class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {

        K = k;

        for(auto &it : nums) {
            pq.push(it);

            if(pq.size() > k) pq.pop();     //minimum element will be popped
        }

    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > K) pq.pop();

        return pq.top();
    }
};
