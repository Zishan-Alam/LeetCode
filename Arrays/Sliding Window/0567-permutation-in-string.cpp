class Solution {
public:

    bool allZero(vector<int> count) {
        for(auto it : count) {
            if(it != 0) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        int n = s2.length();

        vector<int> count(26, 0);

        for(auto ch : s1) {
            count[ch - 'a']++;
        }

        int i = 0;
        int j = 0;

        while(j < n) {
            count[s2[j] - 'a']--;

            if(j - i + 1 == k) {
                if(allZero(count)) return true;

                count[s2[i] - 'a']++;
                i++;
            }
            j++;
        }
        return false;
    }
};
