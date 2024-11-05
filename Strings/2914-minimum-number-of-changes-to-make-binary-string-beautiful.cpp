// Time complexity is O(n) 
// Space complexity is O(1).
class Solution {
public:
    int minChanges(string s) {
        int n = s.length(); 
        int count = 0; // Count variable to track changes 

        // Agar string ka length 2 hai aur dono characters alag hain, toh ek change ki zaroorat hai
        if(n == 2 && s[0] != s[1]) return 1;

        // Loop string ke alternate characters ko check karne ke liye
        for(int i = 0; i < n - 1; i += 2) {

            if(s[i] == '1' && s[i + 1] == '0') count++;         // Agar current pair '10' hai toh count badhao
            else if(s[i] == '0' && s[i + 1] == '1') count++;    // Agar current pair '01' hai toh count badhao
            
        }
        return count;
    }
};
