class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector< vector<char> > result(n, vector<char> (m));

        //Step-01: Taking the transpose
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                result[i][j] = box[j][i];
            }
        }

        //Step-02: Rotating it by 90 degree
        for(vector<char> &vec : result) {
            reverse(vec.begin(), vec.end());
        }

        //Step-03: Applying the gravity

      //Time Complexity : O(col * row * row)
        for(int j=0; j<m; j++) {
            for(int i=n-1; i>=0; i--) {
                if(result[i][j] == '.') {       //Found the space
                    int stoneRow = -1;

                    //searching for the next #
                    for(int k=i-1; k>=0; k--) {
                        if(result[k][j] == '*') break;

                        else if(result[k][j] == '#') {
                            stoneRow = k;
                            break;
                        }
                    }

                    if(stoneRow != -1) {
                        result[i][j] = '#';
                        result[stoneRow][j] = '.';
                    }
                }
            }
        }
        return result;
    }
};

//Optimal approach

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector< vector<char> > result(n, vector<char> (m));

        //Step-01: Taking the transpose
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                result[i][j] = box[j][i];
            }
        }

        //Step-02: Rotating it by 90 degree
        for(vector<char> &vec : result) {
            reverse(vec.begin(), vec.end());
        }

        //Step-03: Applying the gravity

        //Time Complexity : O(col * row)
        for(int j=0; j<m; j++) {
            int spaceBottomRow = n - 1;
            for(int i=n-1; i>=0; i--) {
                if(result[i][j] == '*') {
                    spaceBottomRow = i - 1;
                    continue;
                }

                if(result[i][j] == '#') {
                    result[i][j] = '.';
                    result[spaceBottomRow][j] = '#';
                    spaceBottomRow--;
                }
            }
        }
        
        return result;
    }
};
