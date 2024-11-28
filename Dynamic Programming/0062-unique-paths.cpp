//Dynamic Programming
//time complexity of this solution is O(m * n)
//space complexity is also O(m * n) due to the memoization table `t`
class Solution {
public:

    int t[101][101];  // Memoization table to store intermediate results
    vector<vector<int>> directions{ {0,1}, {1,0} };  // Right and Down directions

    long long int solve(int m, int n, int i, int j) {
        // Agar out of bounds ho, toh return 0 (invalid path)
        if(i >= m || j >= n) return 0;

        // Agar destination (m-1, n-1) pe pahuch gaye hain, toh return 1 (valid path)
        if(i == m-1 && j == n-1) return 1;

        // Memoized result check
        if(t[i][j] != -1) return t[i][j];

        long long int paths = 0;

        // Explore both directions: right and down
        for(auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            paths += solve(m, n, new_i, new_j);     // Recursive call and accumulate paths
        }

       
        return t[i][j] = paths;                      // Store the result in memoization table
    }

    int uniquePaths(int m, int n) {
        
        memset(t, -1, sizeof(t));       //memoization table

        return solve(m, n, 0, 0);       // Call the solve function starting from (0, 0)
    }
};
