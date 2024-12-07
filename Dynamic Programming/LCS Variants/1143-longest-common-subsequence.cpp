//Approach - 01 : Recursive + Memoize (Top - Down)
class Solution {
public:

    int t[1001][1001];

    long long lcs(string text1, string text2, int m, int n) {
        if(m == 0 || n == 0) return 0;      //base condition

        if(t[m][n] != -1) return t[m][n];

        //choice diagram
        if(text1[m-1] == text2[n-1]) {
            return 1 + lcs(text1, text2, m-1, n-1);
        }

        int match1 = lcs(text1, text2, m, n-1);
        int match2 = lcs(text1, text2, m-1, n);

        return t[m][n] =  max(match1, match2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        long long m = text1.length();
        long long n = text2.length();

        memset(t, -1, sizeof(t));

        return lcs(text1, text2, m, n);
    }
};

//Approach - 02 : Bottom Up
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); // DP table
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1; // if match, add 1 to diagonal
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // else take max of top or left
                }
            }
        }
        
        return dp[m][n]; // Final result
    }
};
