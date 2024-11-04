// Time complexity is O(n + m) 
// Space complexity is O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq;

        for(auto it : ransomNote) mp[it]++;
        for(auto it : magazine) mp[it]--;

        for(auto it : freq) if(it > 0) return false;
        return true;
    }
};

// Frequency vector pe sirf ransomNote ke values add horhe hai
// Magazine ke sirf vohi values substract horhe hai, jo already map pe hai
