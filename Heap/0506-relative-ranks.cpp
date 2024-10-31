// Time complexity is O(n log n), logn to insert or pop element and it has been done n times
// Space complexity is O(n) for returning the answer
class Solution {
public:

    typedef pair<int,int> P;
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<P> pq;
        for(int i=0; i<n; i++) {
            pq.push( {score[i], i} );
        }

        int count = 0;
        vector<string> result(n);

        while( !pq.empty() ) {
            
            P temp = pq.top();
            pq.pop();
            count++;

            if     (count == 1) result[temp.second] = "Gold Medal";
            else if(count == 2) result[temp.second] = "Silver Medal";
            else if(count == 3) result[temp.second] = "Bronze Medal";
            else {
                result[temp.second] = to_string(count);
            }
        }
        return result;
    }
};
