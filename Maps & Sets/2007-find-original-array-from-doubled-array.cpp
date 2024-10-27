class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        unordered_map <int,int> mp;
        vector<int> result; // to store the result

        if(n % 2 != 0) return {}; //odd number of elements in vector

        //sorting the elements of array, so that doubled elements appear after non-double ones
        sort(changed.begin(),changed.end());

        //Step-01 : Populate the map with array elements
        for(int i=0; i<n; i++){
            mp[changed[i]]++; 
        }
        //Step-02 : Iterating over the array and finding the twice in map
        for(auto &num : changed){
            int twice = num * 2;

            if(mp[num] == 0) continue; //to skip doubled elements

            if(mp.find(twice) == mp.end() || mp[twice] == 0) return {}; // not found the double element

            result.push_back(num);

            mp[num]--;
            mp[twice]--;
        }
        return result;
        
    }
};
