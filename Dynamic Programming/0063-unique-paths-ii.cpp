//BackTracking
//time complexity is O(2^(m+n)) in the worst case, and the space complexity is O(m + n) due to the recursion stack.
//Time Limie Exceeded
class Solution {
public:

    int m, n;
    int result;
    vector<vector<int>> directions{ {1,0}, {0,1} };     //down, right

    void backtrack(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1) return;

        if(i == m - 1 && j == n - 1) {
            result++;
            return;
        }

        grid[i][j] = 1;

        for(auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            backtrack(grid, new_i, new_j);
        }

        grid[i][j] = 0;     //backtrack
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        result = 0;

        backtrack(grid, 0, 0);

        return result;

    }
};

//Dynamic Programming
//time and space complexity of the solution are O(m * n).
class Solution {
public:

    int m, n;  // Grid ke rows aur columns ka size
    int t[101][101];  // Memoization table: t[i][j] mein store karega number of paths from (i, j) to destination

    // Solve function: recursive memoization approach
    int solve(vector<vector<int>> obstacleGrid, int i, int j) {
        // Agar out of bounds ho ya obstacle (1) milta hai, toh path nahi ho sakta
        if(i < 0 || j < 0 || i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;

        // Agar already memoized result hai, toh use return karo
        if(t[i][j] != -1) return t[i][j];

        // Agar destination (m-1, n-1) pe pahuch gaye hain, toh 1 return karo (path found)
        if(i == m-1 && j == n-1) return 1;

        // Right aur down se possible paths ko explore karte hain
        int right = solve(obstacleGrid, i, j+1);  // Move right
        int down = solve(obstacleGrid, i+1, j);   // Move down

        // Memoization: t[i][j] ko right + down se set karte hain
        return t[i][j] = right + down;  // Return total paths from (i, j)
    }

    // Main function: obstacle grid ko solve karne ke liye
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();  // Grid ke rows ka size
        n = obstacleGrid[0].size();  // Grid ke columns ka size

        // Memoization table ko -1 se initialize karte hain (matlab sabhi cells unvisited hain initially)
        memset(t, -1, sizeof(t));

        // Starting cell (0, 0) se unique paths ko calculate karte hain
        return solve(obstacleGrid, 0, 0);
    }
};
