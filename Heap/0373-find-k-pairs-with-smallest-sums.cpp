// Time complexity is `O(m * n * log k)` 
// Space complexity is `O(k)`.
class Solution {
public:
    typedef pair<int, pair<int,int>> P; // P ko ek type define kar rahe hain jo sum aur index pair ko store karega

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        priority_queue<P> pq; // max-heap (priority queue) ka use kar rahe hain
        vector<vector<int>> res; // result store karne ke liye

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int sum = nums1[i] + nums2[j]; // nums1 aur nums2 ke elements ka sum

                if(pq.size() < k) {
                    pq.push({sum, {i, j}}); // agar queue ka size k se chhota hai toh sum ko push karenge
                }
                else if(pq.top().first > sum) { // agar current sum priority queue ke top se chhota hai toh
                    pq.pop(); // top ko pop karenge
                    pq.push({sum, {i, j}}); // naye sum ko push karenge
                }
                else {
                    break; // agar queue mein sum bada hai toh break karna hai kyunki sorted order mein hain
                }
            }
        }

        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();

            int i = temp.second.first; // first index
            int j = temp.second.second; // second index

            res.push_back({nums1[i], nums2[j]}); // result mein pair ko add karna
        }
        return res; // final result return karna
    }
};

// Time complexity is O(k log k) 
// Space complexity is O(k).
class Solution {
public:

    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        priority_queue<P, vector<P>, greater<P>> pq; // Min-heap
        set<pair<int, int>> visited; // Set to track visited pairs
        vector<vector<int>> result;

        // Initial pair {0,0} ko push karna
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        visited.insert({0, 0});

        while (k-- && !pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({nums1[i], nums2[j]});

            // Push {i, j+1} if possible
            if (j < n - 1 && visited.find({i, j + 1}) == visited.end()) {
                int sum = nums1[i] + nums2[j + 1];
                pq.push({sum, {i, j + 1}});
                visited.insert({i, j + 1});
            }
            // Push {i+1, j} if possible
            if (i < m - 1 && visited.find({i + 1, j}) == visited.end()) {
                int sum = nums1[i + 1] + nums2[j];
                pq.push({sum, {i + 1, j}});
                visited.insert({i + 1, j});
            }
        }
        return result;
    }
};

