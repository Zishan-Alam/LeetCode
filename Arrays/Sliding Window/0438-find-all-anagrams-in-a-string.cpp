//time complexity of the given solution is O(n)
//space complexity can be considered O(1)
class Solution {
public:

    bool allZero(vector<int> counter) {
        for(auto it : counter) {
            if(it != 0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.length();

        vector<int> counter(26, 0);     //count of characters in the p string

        //Filling the counter vector
        for(auto ch : p) {
            counter[ch - 'a']++;        //ch - 'a' corresponds to the index of each character
        }

        int i = 0;
        int j = 0;

        int k = p.length();
        vector<int> result;

        //Sliding window approach
        while(j < n) {
            counter[s[j] - 'a']--;      //decreasing the count of char while traversing the s string

            if(j - i + 1 == k) {        //window reached
                if(allZero(counter)) {
                    result.push_back(i);
                }

                counter[s[i] - 'a']++;  //increasing the count of char once again if anagram is not found
                i++;
            }
            j++;
        }
        return result;
    }
};
