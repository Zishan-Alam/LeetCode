class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        if(m != n) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(auto &ch : word1) freq1[ch-'a']++;
        for(auto &ch : word2) freq2[ch-'a']++;

        // 1st : jo char word1 mai hai, vo word2 mai bhi hona chahiye
        for(int i=0; i<26; i++) {
            if(freq1[i] != 0 and freq2[i] != 0) continue;
            if(freq1[i] == 0 and freq2[i] == 0) continue;

            return false;
        }

        //2nd : dono ki frequncy same honi chaiye
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
