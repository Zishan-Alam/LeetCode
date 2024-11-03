// Time Complexity: O(n * m) where m --> length of longest message
// Space Complexity: O(n)
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        // Step 1: Initialize an unordered_map to store the total word count for each sender
        unordered_map<string, int> mp;

        // Step 2: Count words in each message and update the word count for each sender
        for(int i = 0; i < messages.size(); i++) {
            string s = messages[i];
            int words = 1;  // Initially set words to 1 as the minimum number of words

            // Count spaces in the message to calculate the number of words
            for(auto &ch : s) if(ch == ' ') words++;

            // Update the word count for the sender
            mp[senders[i]] += words;
        }

        // Step 3: Find the sender with the maximum word count
        int maxi = INT_MIN;  // Initialize maxi to store the maximum word count
        string ans = "";  // Initialize ans to store the sender with the highest word count

        for(auto &it : mp) {
            // Update if the current sender's word count is higher than the max count
            // OR if the count is the same but the sender name is lexicographically greater
            if(it.second > maxi || (it.second == maxi && it.first > ans)) {
                maxi = it.second;
                ans = it.first;
            }
        }

        // Step 4: Return the sender with the highest word count
        return ans;
    }
};
