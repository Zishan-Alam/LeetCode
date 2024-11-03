// Time Complexity: O(n + k log k), which can be O(n log n) in the worst case.
// Space Complexity: O(k), which can be O(n) in the worst case where k --> number of unique elements in the array
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int half = n/2;

        unordered_map<int,int> mp;                  //map to count the frequency of each element
        for(auto &it : arr) mp[it]++;

        priority_queue<int> pq;                     // Max heap to store frequencies in descending order
        for(auto &it : mp) pq.push(it.second);

        int count = 0;              // Count of elements to remove
        int removed = 0;            // Number of elements removed so far

        while(!pq.empty()) {
            auto temp = pq.top();           // Remove elements with the highest frequency first
            pq.pop();

            removed += temp;                // Add frequency to removed count
            count++;

            if(removed >= half) break;      // Check if we have removed enough elements to reduce the array size to half
        }
        return count;
    }
};
