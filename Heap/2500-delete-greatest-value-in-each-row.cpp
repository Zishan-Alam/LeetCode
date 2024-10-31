// Time Complexity: O(m * n log n)
// Space Complexity: O(1)
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        //Step-01 : Sorting the rows in descending order
        for(int i=0; i<m; i++) {
            sort(grid[i].begin(), grid[i].end(), greater<int>());
        }

        //Step-02 : Now all the large elements are aligned at the left
        for(int j=0; j<n; j++) {
            int columnMax = 0;
            for(int i=0; i<m; i++) {
                columnMax = max(columnMax, grid[i][j]);
            }
            ans += columnMax;
        }
        return ans;
    }
};
