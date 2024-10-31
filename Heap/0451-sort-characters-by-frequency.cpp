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
