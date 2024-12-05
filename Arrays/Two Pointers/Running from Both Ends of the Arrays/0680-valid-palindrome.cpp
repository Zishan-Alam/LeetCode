class Solution {
public:

    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;

        while(start<=end){
            if(s[start] == s[end]){
                start++;
                end--;
            }
            //if there is a mismatch, try skipping either start or end
            else{
                bool res = (isPalindrome(s, start+1, end) || isPalindrome(s, start, end-1));
                return res;
            }
        }
        return true;
    }
};
