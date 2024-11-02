// Time Complexity: O(n + m log k + k log k), where m --> number of unique words in map
// Space Complexity: O(m + k), where m --> number of unique words in map, k --> size of heap and input

class Solution {
public:

    typedef pair<int, string> P; // {frequency, string}

    // Custom comparator lambda jo min-heap create karta hai, same frequency ke case mein lexicographical order check karta hai
    struct lambda {
        bool operator()(P &p1, P &p2) {
            // Agar frequency same hai, toh lexicographical order mein arrange karo
            return (p1.first == p2.first) ? p1.second < p2.second : p1.first > p2.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;

        unordered_map<string, int> mp;
        // Har word ka frequency count karne ke liye unordered_map ka use
        for (auto s : words) mp[s]++;
        
        // Min-heap to keep top k elements with custom lambda comparator
        priority_queue<P, vector<P>, lambda> pq;
        
        // Map ke har element ko priority queue mein daalo
        for (auto it : mp) {
            pq.push({it.second, it.first}); // Frequency aur word ko pair mein push kar rahe hain

            // Agar queue ka size k se bada ho gaya, toh minimum frequency element ko pop karte hain
            if (pq.size() > k) pq.pop();
        }

        // Priority queue se result collect karte hain
        while (!pq.empty()) {
            P temp = pq.top(); // Top element (min frequency ya lexicographically smaller)
            pq.pop();

            result.push_back(temp.second); // Word ko result mein add karte hain
        }

        // Kyunki elements ascending order mein hain, result ko reverse karte hain descending order mein
        reverse(result.begin(), result.end());
        return result; // Final result return
    }
};
