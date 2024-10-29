// Builtin function
// TC : 0(nlogn)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);

        for(int i=0; i<res.size(); i++) { //n times 
            res[i] = __builtin_popcount(i); //every number has logn bits if the number is n
        }
        return res;
        
    }
};

// 0(n) approach

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
