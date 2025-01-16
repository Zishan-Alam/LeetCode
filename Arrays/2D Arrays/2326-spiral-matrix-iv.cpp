class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;

        int dir = 0;
        vector<vector<int>> matrix(m, vector<int> (n,-1));

        while(top <= down && left <= right) {

            if(dir == 0) {
                //left to right
                //constant : top (row)
                for(int i=left; head!= nullptr && i<=right; i++) {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            if(dir == 1) {
                //top to bottom
                //constant : right (col)
                for(int i=top; head!= nullptr && i<=down; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }

            if(dir == 2) {
                //right to left
                //constant : down (row)
                for(int i=right; head!= nullptr && i>=left; i--) {
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }

            if(dir == 3) {
                //down to top
                //constant : left (col)
                for(int i=down; head!= nullptr && i>=top; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            dir = (dir+1) % 4;
        }
        return matrix;
    }
};
