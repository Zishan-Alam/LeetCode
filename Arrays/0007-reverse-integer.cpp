class Solution {
public:
    int reverse(int x) {
        long long int rev = 0;
        
        while(x!=0){
            
            int lastDigit = x % 10;
            
            if(rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
            
            rev = (rev * 10) + lastDigit;
            
            x = x / 10;
        }
        
        return rev; 
    }
};




