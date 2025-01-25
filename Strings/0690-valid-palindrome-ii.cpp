class Solution {
public:

    bool isPalindrome(string s, int left, int right) {
        while(left <= right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left  = 0;
        int right = s.length()-1;

        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else{
                bool ans = isPalindrome(s, left+1, right) or isPalindrome(s, left, right-1);
                return ans;
            }
        }
        return true;
    }
};
