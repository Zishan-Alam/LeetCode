class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;

        for(int i=0; i<24; i++) {   //10^7 is the maximum number in constraints
            int count = 0;

            for(auto num : candidates) {    //checking each bit of each number

                if( (num & (1 << i)) != 0) count++;
            }
            result = max(result,count);
        }
        return result;
    }
};
