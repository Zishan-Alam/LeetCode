class Solution {
public:
    bool rotateString(string s, string goal) {
        // Agar 's' aur 'goal' ka length alag hai toh wo kabhi rotation nahi ho sakta,
        // isliye false return karte hain
        if (s.length() != goal.length()) return false;

        // 's + s' ka matlab hai 's' ko khud se jodna (concatenate karna).
        // Agar s = "abc" hai, toh (s + s) = "abcabc" ban jayega.
        // Isse hum check kar sakte hain ki kya goal, s ka rotation hai.
        return (s + s).find(goal) != string::npos;

        /* 
        1.) (s + s): Yeh s ko khud se concatenate karta hai. Agar s = "abc" ho,
            toh (s + s) "abcabc" ban jata hai, jisse hum goal ko dhoondh sakte hain.
        
        2.) .find(goal): Yeh find function goal substring ko (s + s) mein dhoondhta hai.
        
        3.) string::npos: Yeh C++ mein ek constant hai jo "no position" ko darshata hai.
            Agar find function ko goal nahi milta, toh yeh string::npos return karta hai.
        
        4.) != string::npos: Yeh check karta hai ki goal (s + s) mein milta hai ya nahi.
            Agar milta hai toh find ek valid position return karega aur result true hoga.
            Agar nahi milta, toh yeh string::npos return karega aur expression false hoga.
        */
    }
};
