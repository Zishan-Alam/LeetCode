class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0) return {};

        int m = n;
        vector<vector<int>> matrix(m, vector<int> (n));

        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;

        int dir = 0;
        int count = 1;

        while(top <= down && left <= right) {

            if(dir == 0) {
                //left to right
                //constant : top (row)
                for(int i=left; i<=right; i++) {
                    matrix[top][i] = count++;
                }
                top++;
            }

            if(dir == 1) {
                //top to down
                //constant : right (col)
                for(int i=top; i<=down; i++) {
                    matrix[i][right] = count++;
                }
                right--;
            }

            if(dir == 2) {
                //right to left
                //constant : down (row)
                for(int i=right; i>=left; i--) {
                    matrix[down][i] = count++;
                }
                down--;
            }

            if(dir == 3) {
                //down to top
                //constant : left (col)
                for(int i=down; i>=top; i--) {
                    matrix[i][left] = count++;
                }
                left++;
            }
            dir++;
            if(dir == 4) dir = 0;
        }
        return matrix;
    }
};
