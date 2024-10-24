class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int x=0;

        for(int i=0; i<n; i++){
            (operations[i][1] == '-') ? x-- : x++;        
        }
        return x;
    }
};
