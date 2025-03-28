class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        if(m > n) return false;

        int i = 0;      // iterate over s
        int j = 0;      // iterate over t

        while(i < m && j < n) {
            if(s[i] == t[j]) i++;
            j++;
        }

        return i == m;
    }
};
