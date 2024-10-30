// TC : 0(n)
// SC : 0(1) additional space is 0(2n) where n is length of each string
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        string newString  = s + t;
        int size  = newString.size();
        for(int i=0; i<size; i++) {
            ans = ans ^ newString[i];
        }
        return ans;
    }
};

// TC : 0(nlogn) where n is the length of each string
// SC : 0(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        int n = t.size();

        for(int i=0; i<n; i++){
            if(s[i] != t[i]) return t[i];
        }
        return t[0];
    }
};

// TC : 0(2n) iterating both the strings
// SC : 0(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int asciSumS = 0;
        int asciSumT = 0;

        for(auto it : s) asciSumS += int(it);
        for(auto it : t) asciSumT += int(it);

        return char(asciSumT - asciSumS);
    }
};
