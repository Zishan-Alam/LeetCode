class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();

        //Step-01: taking transpose.
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //Step-02: reversing each row of matrix.
        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
