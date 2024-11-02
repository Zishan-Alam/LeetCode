// Time complexity is O(m * n * log k) 
// Space complexity is O(k). where k is the number of the elements on the heap and the input given
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<int> pq;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                pq.push(matrix[i][j]);

                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
        
    }
};
