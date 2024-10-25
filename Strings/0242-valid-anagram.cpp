//................................................................Sorting Approach...................................................................................//

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//................................................................Hash Map Approach..................................................................................//
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mp;

        for(auto it : s){
            mp[it]++;
        }

        for(auto it : t){
            mp[it]--;
        }

        for(auto it : mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
