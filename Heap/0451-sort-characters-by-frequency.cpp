class Solution {
public:

    // Pair ko shorthand ke liye typedef kiya, yahan P = pair<char,int> hai
    typedef pair<char, int> P;

    // Custom comparator struct jo lambda ki tarah kaam karega, max heap ke liye
    struct lambda {
        // Comparator function jo pair ke second element ke basis pe sorting karega (frequency)
        bool operator()(P &p1, P &p2) {
            return p1.second < p2.second; // max heap, jisme higher frequency wale elements top pe honge
        }
    };

    string frequencySort(string s) {

        // Map jo character aur uski frequency ko store karega
        unordered_map<char, int> mp;

        // Priority queue (max heap) jo characters ko frequency ke hisaab se sort karegi
        priority_queue<P, vector<P>, lambda> pq;

        // String ke har character ki frequency count kar rahe hain
        for (auto &ch : s) mp[ch]++;

        // Map ke har element ko priority queue mein daal rahe hain {character, frequency}
        for (auto &it : mp) pq.push({it.first, it.second}); 

        // Resultant answer string jo sorted order mein characters ko store karegi
        string ans = "";

        // Priority queue se characters ko frequency ke hisaab se result mein daal rahe hain
        while (pq.size() != 0) {
            P temp = pq.top();
            pq.pop();

            // Frequency ke hisaab se character ko result string mein add karte hain
            ans += string(temp.second, temp.first);
        }

        // Final sorted string return kar rahe hain
        return ans;
    }
};

/*Time Complexity:
1. Counting Frequencies: The first loop iterates through the string `s` of length `n`, resulting in O(n) time complexity for counting the frequency of each character.
2. Inserting into Priority Queue: The second loop iterates through the frequency map, which can have at most `k` unique characters (where `k` is the number of distinct characters in the string). Inserting each character into the priority queue takes O(log k) time. Thus, this step takes O(k log k).
3. Building the Result String: The while loop processes each character in the priority queue. Since there are `k` unique characters, and for each character, we add it to the result string based on its frequency, this step takes O(n) time in total.

Combining these steps, the overall time complexity is O(n + k log k). In the worst case, where all characters are unique (k = n), this simplifies to O(n log n).

Space Complexity:
1. Frequency Map: The unordered_map stores at most `k` unique characters, leading to O(k) space complexity.
2. Priority Queue: The priority queue also stores at most `k` elements, contributing another O(k) space complexity.
3. Result String: The result string will store all `n` characters, leading to O(n) space complexity.

Overall, the space complexity is O(n + k), but since k can be at most n, the space complexity can be simplified to O(n) in the worst case. */
