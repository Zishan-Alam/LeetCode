//Redundant Function
class Solution {
public:

    bool allCapital(string word) {
        for(auto &ch : word) {
            if(ch < 'A' or ch > 'Z') return false;
        }
        return true;
    }
    bool allSmall(string word) {
        for(auto &ch : word) {
            if(ch < 'a' or ch > 'z') return false;
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        if(allCapital(word) or allSmall(word) or allSmall(word.substr(1))) return true;

        return false;
    }
};

//Simpler Solution
class Solution {
public:

    bool check(string word, char start, char end) {
        for(auto &ch : word) {
            if(ch < start or ch > end) return false;
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        if(check(word, 'A', 'Z') or check(word, 'a', 'z') or check(word.substr(1), 'a', 'z')) return true;

        return false;
    }
};

//Second Approach
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int count = 0;

        for(char &ch : word) {
            if(isupper(ch)) count++;
        }

        return (count == 0 or count == n or (count == 1 and isupper(word[0])) );
    }
};
