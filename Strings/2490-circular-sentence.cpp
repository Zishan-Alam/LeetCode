class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        // Agar pehla aur aakhri character same nahi hai toh circular nahi ho sakta
        if (sentence[0] != sentence[n - 1]) return false;

        // Loop space characters ke beech ke characters check karne ke liye
        for (int i = 1; i<n-1; i++) {
            if (sentence[i] == ' ') {
                // Agar previous aur next character same nahi hai toh circular nahi hai
                if (sentence[i - 1] != sentence[i + 1]) return false;
            }
        }
        
        // Agar sab checks pass ho gaye toh circular hai
        return true;
    }
};
