// Time Complexity: O(n + k * log n)
// Space Complexity: O(n)
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;     //default max heap

        int sum = 0;
        
        // Pushing elements into the heap and calculating sum   O(n)
        for(auto it : piles) { 
            pq.push(it);
            sum += it;
        }

        // Removing the maximum elements    O(k * logn)
        while( k != 0) { 
            int maxi = pq.top();
            pq.pop();

            int remove = maxi/2;

            sum -= remove;

            maxi -= remove;

            pq.push(maxi); //O(logn) to rearrange the elements of heap

            k--;
        }
        return sum;
    }
};
