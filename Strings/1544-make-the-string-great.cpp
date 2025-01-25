class Solution {
public:
    string makeGood(string s) {
        string res = "";

        for(char &ch : s) {

            if(!res.empty() && (res.back() + 32 == ch || res.back() - 32 == ch) ) {
                res.pop_back();
            }
            else res.push_back(ch);
        }
        return res;
    }
};

/* 
a = A + 32
b = B + 32
c = C + 32
d = D + 32
..
..
..
*/
