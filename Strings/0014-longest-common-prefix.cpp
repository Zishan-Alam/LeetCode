class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; 

        string res = "";
        int m = strs[0].size(); // Pehli string ke length

        for (int i = 0; i < m; i++) {
            char ch = strs[0][i]; // Pehli string ka current character

            // Check for all strings
            for (auto& s : strs) {
                if (i >= s.size() || s[i] != ch) // Agar index out of range ho ya mismatch ho
                    return res;
            }
            res += ch; // Add character to result if all match
        }
        return res;
    }
};
