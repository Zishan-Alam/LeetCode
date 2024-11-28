class Solution {
public:

    int m, n;  // Grid ke row aur column ka size
    int result;  // Unique paths count karne ke liye
    int nonObsCount;  // Non-obstacle cells ka count (start + empty cells)
    vector<vector<int>> directions{ {1,0}, {0,1}, {-1,0}, {0,-1} }; // Directions: down, right, up, left

    // Backtracking function
    void backtrack(vector<vector<int>> &grid, int i, int j, int count) {
        // Agar out of bounds ho jaaye ya obstacle cell pe aaye, toh return karo
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) return;

        // Agar destination (2) mil jaata hai aur sab cells ko visit kiya gaya ho
        if(grid[i][j] == 2) {
            if(count == nonObsCount) {  // Agar count equals non-obstacle count hai
                result++;  // Valid path mila
            }
            return;
        }

        // Current cell ko mark karte hain as visited (backtracking ke liye)
        grid[i][j] = -1;

        // Har direction mein explore karte hain
        for(auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            // Recursively backtrack karte hain
            backtrack(grid, new_i, new_j, count + 1);
        }

        // Backtrack: current cell ko unvisited mark karte hain
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();  // Grid ke rows ka size
        n = grid[0].size();  // Grid ke columns ka size

        result = 0;  // Initializing result
        nonObsCount = 0;  // Non-obstacle cells count initialize

        int start_i, start_j;  // Start cell coordinates

        // Grid ko scan karte hain to find start (1) and empty (0) cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {  // Start position found
                    nonObsCount++;
                    start_i = i;
                    start_j = j;
                }
                if(grid[i][j] == 0) nonObsCount++;  // Empty cell count karte hain
            }
        }

        int count = 0;  // Start position se count 0 se start karte hain

        // Backtrack se unique paths count karte hain
        backtrack(grid, start_i, start_j, count);

        return result;  // Total unique paths return karte hain
    }
};
