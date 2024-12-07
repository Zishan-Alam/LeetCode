//LPS(a) = LCS(a, reverse(a) )
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;          // Copy the string s
        reverse(t.begin(), t.end());  // Reverse string t

        int m = s.length();
        int n = t.length();

        // DP table to store the length of the longest common subsequence
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Fill the DP table
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == t[j-1]) {  // If characters match
                    dp[i][j] = 1 + dp[i-1][j-1]; // Extend the subsequence
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // Take the max of the two possibilities
                }
            }
        }

        // The length of the longest palindromic subsequence is the value in dp[m][n]
        return dp[m][n];
    }
};
