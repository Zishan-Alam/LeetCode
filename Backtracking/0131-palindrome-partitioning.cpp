//time complexity is O(n * 2^n) 
//space complexity is O(n * 2^n).
class Solution {
public:

    int n;
    vector<vector<string>> result;

    bool isPalindrome(string &s, int l, int r) {

        while(l < r) {
            if(s[l] != s[r]) return false;

            l++;
            r--;
        }
        return true;
    }

    void backtrack(int idx, string &s, vector<string> temp) {
        if(idx == n) {
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<n; i++) {

            if(isPalindrome(s, idx, i)) {

                temp.push_back(s.substr(idx, i-idx+1));
                backtrack(i+1, s, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        n = s.length();
        backtrack(0, s, temp);
        return result;
    }
};
