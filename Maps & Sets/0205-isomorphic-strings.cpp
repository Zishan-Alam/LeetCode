// TC : 0(n)
// SC : 0(1), since the maximum number of unique characters that can be stored in the unordered maps is limited by the character set (for example, 256 for extended ASCII or 26 for lowercase English letters).
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();

        unordered_map<char, char> mp1; // s to t
        unordered_map<char, char> mp2; // t to s

        for (int i = 0; i < n; i++) {

            char ch1 = s[i];
            char ch2 = t[i];

            if ((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) ||
                (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)) {
                return false;
            } else {
                mp1[ch1] = ch2;
                mp2[ch2] = ch1;
            }
        }
        return true;
    }
};
