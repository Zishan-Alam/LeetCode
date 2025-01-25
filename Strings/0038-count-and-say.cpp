class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string say = countAndSay(n-1);
        string result = "";

        //Processing
        for(int i=0; i<say.length(); i++) {

            char ch = say[i];
            int count = 1;

            while(i < say.length()-1 && say[i] == say[i+1]) {
                count++;
                i++;
            }
            result += to_string(count) + string(1, ch);     //ch to string --> string(1, ch) || int to string --> to_string(count)
        }
        return result;
    }
};
