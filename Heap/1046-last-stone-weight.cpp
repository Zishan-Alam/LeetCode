//Time complexity - O(n^2 log n)
//Space complexity - O(1).
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while( stones.size() > 1 ) {            //O(n)
            sort(stones.begin(), stones.end()); //O(nlogn)

            int a = stones.back();      //largest element
            stones.pop_back();

            int b = stones.back();     //second largest element
            stones.pop_back();

            stones.push_back( abs(a-b) );
        }
        return stones[0];
    }
};

//Time complexity - O(n log n)
//Space complexity - O(n).

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;     //maxHeap

        for(auto it : stones) pq.push(it);

        while( pq.size() > 1 ) {                    //O(n)

            int largest = pq.top(); pq.pop();       //pop --> O(logn)
            int slargest = pq.top(); pq.pop();      //pop --> O(logn)

            pq.push( abs(largest-slargest) );       //push --> O(logn)
        }

        return pq.top();
    }
};

