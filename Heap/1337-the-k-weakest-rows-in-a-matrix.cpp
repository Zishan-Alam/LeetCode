// Time complexity is O(m * n) 
// Space complexity is O(m + k). where k --> size of pq
class Solution {
public:
    typedef pair<int, int> P;

    struct lambda {
        bool operator()(P &p1, P &p2) {
            // Ascending order, max-heap for soldier count and lexicographical order by row index
            return (p1.first == p2.first) ? p1.second < p2.second : p1.first < p2.first;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();

        // Step 1: Count the number of soldiers in each row and store in a map
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++) {
            int soldierCount = count(mat[i].begin(), mat[i].end(), 1);
            mp[i] = soldierCount;
        }

        // Step 2: Use a max-heap to keep track of the k weakest rows
        priority_queue<P, vector<P>, lambda> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop();  // Remove the strongest row if size exceeds k
        }

        // Step 3: Extract elements from the priority queue in the correct order
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        // The priority queue gives us the rows in descending order of strength,
        // so we need to reverse the result for ascending order
        reverse(result.begin(), result.end());
        return result;
    }
};
