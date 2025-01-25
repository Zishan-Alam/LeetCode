//With Space
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s = "";
        string t = "";

        for(auto str : word1) s += str;
        for(auto str : word2) t += str;

        return (s == t);
    }
};

//Without Space
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();

        int w1 = 0; int i = 0;     //to iterate in word 1
        int w2 = 0; int j = 0;     //to iterate in word 2

        while(w1 < m && w2 < n) {

            if(word1[w1][i] != word2[w2][j]) return false;
            i++;
            j++;

            if(i == word1[w1].length()) i = 0, w1++;
            if(j == word2[w2].length()) j = 0, w2++;
        } 
        return (w1 == word1.size() && w2 == word2.size());
    }
};
