class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill dp table for LCS calculation
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        int i = m, j = n;
        string ans = "";

        // Build the Shortest Common Supersequence (SCS) from the dp table
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    ans.push_back(str1[i - 1]);
                    i--;
                } else {
                    ans.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        // If any characters are left in str1 or str2, add them
        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }

        // Reverse the result string to get the final SCS
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
