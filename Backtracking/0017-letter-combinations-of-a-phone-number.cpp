// Time Complexity: O(4^n)
// Space Complexity: O(n * 4^n)
class Solution {
public:

    vector<string> result;

    void solve(int idx, string &temp, string digits, unordered_map<char, string> mp) {
        if(idx == digits.length()) {
            result.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];

        for(auto it : str) {

            temp.push_back(it);                 //Do
            solve(idx+1, temp, digits, mp);     //Explore
            temp.pop_back();                    //Undo
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};

        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";

        solve(0, temp, digits, mp);

        return result;
    }
};
