class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map < int, vector<int> > mp;

        //Step-01 : Store the diagonal elements
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        //Step-02 : Sort the diagonal elements present in vector of map
        for(auto &it : mp){
            sort(it.second.begin(), it.second.end());
        }
        //Step-03 : Restore the elements back in the matrix
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                mat[i][j] = mp[i-j].back(); //iterating ulta coz agar sidha karte to, har element ko ek step aage lana padta upon .front() operation
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};
