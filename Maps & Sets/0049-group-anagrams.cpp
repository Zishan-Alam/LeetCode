class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector< vector<string> > result; // Final result jo grouped anagrams store karega

        unordered_map< string,vector<string> >mp; // sorted strings as keys and corresponding anagram groups as values

        // Loop through each string in `strs`
        for(int i=0; i<n; i++){
            string temp = strs[i]; // Current string ko temp mein copy karte hain

            sort(begin(temp), end(temp)); // Temp string ko sort karte hain taaki anagrams same key ke under group ho sakein

            mp[temp].push_back(strs[i]); // Original string ko sorted key ke corresponding vector mein add karte hain

        }
        for(auto it : mp){
            result.push_back(it.second); // Each value in map is a group of anagrams
        }

        return result;
    }
};
