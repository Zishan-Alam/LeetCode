
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);

        if(n == 0) return result;

        result[0] = 0;

        for(int i=0; i<result.size(); i++) {

            if( i % 2 == 0) result[i] = result[i/2];
            else result[i] = result[i/2] + 1;

        }
        return result;
    }
};
