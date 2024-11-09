// TC : O(n)
// SC : O(1)
class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;      //the first number of the array will always be that number
        
        //finding next n-1 numbers
        for(int i=0; i<n-1; i++) {
            num = (num+1) | x;  //keeping the bits intact that are present in x
        }
        return num;
    }
};
