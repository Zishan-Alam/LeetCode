class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0;
        int end = num;

        while(start<=end){
            long long int mid = start + (end-start)/2;
            long long int square = mid*mid;

            if(square == num){
                return true;
            }
            else if(square > num){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return false;
    }
};
