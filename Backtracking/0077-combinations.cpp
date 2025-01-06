//- Time Complexity: O(k * C(n, k))
//- Space Complexity: O(k * C(n, k))
class Solution {
public:

    vector<vector<int>> result;

    void solve(int start, int n, int k, vector<int> &temp) {
        if(k == 0) {
            result.push_back(temp);
            return;
        }

        if(start > n) return;

        temp.push_back(start);          //Do (number ko leliya)
        solve(start+1, n, k-1, temp);   //Explore (aage explore karein)
        temp.pop_back();                //Undo (number ko remove)
        solve(start+1, n, k, temp);     //agar number ko ni liya
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, n, k, temp);
        return result;
    }
};

// 2nd approach, same backtrack but with for loop
class Solution {
public:

    vector<vector<int>> result;

    void solve(int start, int n, int k, vector<int> &temp) {
        if(k == 0) {
            result.push_back(temp);
            return;
        }

        for(int i=start; i<=n; i++) {

            temp.push_back(i);
            solve(i+1, n, k-1, temp);
            temp.pop_back();

        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, n, k, temp);
        return result;
    }
};
