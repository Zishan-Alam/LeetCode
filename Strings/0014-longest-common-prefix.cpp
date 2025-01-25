class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // Edge case: Empty input

        string res = "";
        int n = strs[0].size();

        for (int i = 0; i < n; i++) {
            for (auto &s : strs) {
                // Edge case: Index out of bounds or mismatch
                if (i >= s.size() || s[i] != strs[0][i]) //strs[0][i] for reference
                  return res;
            }
            res += strs[0][i]; // Add the common character to result
        }
        return res;
    }
};
