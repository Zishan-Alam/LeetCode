class Solution {
public:

    int m;  // Board ke rows ka size
    int n;  // Board ke columns ka size

    // Directions array: up, down, right, left
    vector<vector<int>> directions{ {1,0}, {-1,0}, {0,1}, {0, -1} };

    // DFS function jo board pe word ko find karta hai
    bool find(vector<vector<char>>& board, int i, int j, int idx, string word) {
        // Agar index word ki length ke barabar ho gaya hai, matlab word pura mil gaya
        if(idx == word.length()) return true;

        // Agar boundary se bahar jaa rahe hain ya already visited cell pe hain, toh false return karo
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') return false;

        // Agar current cell ka character word ke current character ke equal nahi hai
        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];  // Current cell ka character store karo
        board[i][j] = '$';  // Current cell ko visited mark karo (visited cells ko '$' se mark karte hain)

        // Har direction (up, down, left, right) me move karke word ke baaki characters ko match karte hain
        for(auto &dir : directions) {
            int new_i = i + dir[0];  // New row index
            int new_j = j + dir[1];  // New column index

            // Agar adjacent cell se word mil jaata hai toh true return karo
            if(find(board, new_i, new_j, idx + 1, word)) return true;
        }

        // Backtrack: Agar word nahi milta, toh current cell ko wapas original value pe set karo
        board[i][j] = temp;

        return false;  // Agar word kisi bhi direction me match nahi hota toh false return karo
    }

    // Main function jahan board ko explore karte hain
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();  // Rows ki count
        n = board[0].size();  // Columns ki count

        // Har cell se start karke word ko search karte hain
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Agar first character match hota hai toh DFS ko call karte hain
                if(board[i][j] == word[0] && find(board, i, j, 0, word)) return true;
            }
        }

        return false;  // Agar koi bhi cell se word match nahi hota toh false return karo
    }
};
