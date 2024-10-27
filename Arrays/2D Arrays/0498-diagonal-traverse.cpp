class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        map <int, vector<int> > mp; //diagonals ko ascending order mein process karna hai isliye ordered map
        vector<int> result;

        //Step-01 : Fill the map 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flip = true; // toggle to reverse alternate elements

        //Step-02 : Filling the vector as per the question
        for(auto &it : mp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto &num : it.second){
                result.push_back(num);
            }
            flip = !flip;
        }
        return result;
    }
};
