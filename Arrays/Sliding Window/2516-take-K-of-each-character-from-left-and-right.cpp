class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();

        int countA = 0;
        int countB = 0;
        int countC = 0;

        // String ke har character ki frequency calculate kar rahe hain
        for(char &ch : s) {
            if(ch == 'a') countA++;  // Agar 'a' mila to countA badhao
            else if(ch == 'b') countB++; // Agar 'b' mila to countB badhao
            else countC++;          // Agar 'c' mila to countC badhao
        }

        // Agar kisi bhi character ka count k se kam hai, to -1 return karte hain
        if(countA < k || countB < k || countC < k) return -1;

        int i = 0;
        int j = 0;
        int notDeletedWindowSize = 0;  // Maximum window size jo delete nahi karni hai

        while(j < n) {
            if(s[j] == 'a') countA--;  // Window mein 'a' ko include karte waqt countA ghatao
            else if(s[j] == 'b') countB--;  // 'b' ke liye countB ghatao
            else if(s[j] == 'c') countC--;  // 'c' ke liye countC ghatao

            // Agar kisi bhi character ka count k se kam ho gaya hai,
            // to window ko shrink karo aur count ko restore karo
            while(i <= j && (countA < k || countB < k || countC < k)) {
                if(s[i] == 'a') {
                    countA++;  // Window se 'a' ko hata kar countA badhao
                }
                else if(s[i] == 'b') {
                    countB++;  // 'b' ke liye countB badhao
                }
                else if(s[i] == 'c') {
                    countC++;  // 'c' ke liye countC badhao
                }
                i++;  // Window ko aage badhao
            }

            // Not deleted window size ka maximum calculate karo
            notDeletedWindowSize = max(notDeletedWindowSize, j - i + 1);
            j++;  // Window ka end aage badhao
        }
        
        // Total characters minus not deleted window size return karo (minutes)
        return n - notDeletedWindowSize;
    }
};
