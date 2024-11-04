// TC : 0(n)
// SC : 0(1)
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int count = 0;

        unordered_map<char,int> romanMap;
        romanMap.insert( {'I', 1} );
        romanMap.insert( {'V', 5} );
        romanMap.insert( {'X', 10} );
        romanMap.insert( {'L', 50} );
        romanMap.insert( {'C', 100} );
        romanMap.insert( {'D', 500} );
        romanMap.insert( {'M', 1000} );

        for(int i=0; i<n; i++) {
            if(i < n-1 && romanMap[s[i]] < romanMap[s[i+1]]) count -= romanMap[s[i]];
            else count += romanMap[s[i]];
        }
        return count;
    }
};
