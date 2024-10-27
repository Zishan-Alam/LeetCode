    //same as leetcode 2007 but there are negative elements//

class Solution {
public:

    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int,int> mp;

        sort(arr.begin(),arr.end());

        for(auto it : arr) mp[it]++;

        for(auto num : arr){
            //if negative divide by 2, in case of odd number uska corresponding (odd*2) check karenge, jo usse 
            //pehle hi aagya hoga, coz of sorting
            int twice = (num<0 && num%2==0)? num/2 : num*2; 

            if(mp[num] == 0 ) continue;

            if(mp.find(twice) == mp.end() || mp[twice] == 0) return false;

            mp[num]--;
            mp[twice]--;
        }
        return true;
    }
};
