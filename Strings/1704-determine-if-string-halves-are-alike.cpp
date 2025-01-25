class Solution {
public:

    bool isVowel(char ch) {
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'
        or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') return true;

        return false;
    }

    bool halvesAreAlike(string s) {
        int n = s.length();

        int i = 0;   int left = 0;
        int j = n/2; int right = 0;

        while(i < n/2 && j < n) {

            if(isVowel(s[i])) left++;
            if(isVowel(s[j])) right++;

            i++;
            j++;
        }

        return left == right;
    }
};
