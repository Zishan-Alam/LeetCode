//Approach-1 (Recur + Memo)
class Solution {
public:

    int t[101];

    int solve(vector<int> &nums, int i, int n) {
        if(i >= n) return 0;

        if(t[i] != -1) return t[n];

        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;        //starting from the first house

        memset(t, -1, sizeof(t));
        return solve(nums, i, n);
    }
};

//Approach-2 (Bottom up)
class Solution {
public:

    int solve(vector<int> &nums, int i, int n) {
        if(i >= n) return 0;

        int t[n+1];
        //State Definition
        //t[i] --> max money till ith house

        t[0] = 0;
        t[1] = nums[0];

        for(int i=2; i<=n; i++) {

            int skip  = t[i-1];
            int steal = nums[i-1] + t[i-2];
          
            t[i] = max(skip, steal);
        }
        return t[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n);
    }
};

//Approach-3 (Space Optimized Bottom Up - Converting Approach-2)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prevPrev = 0;
        int prev     = nums[0];
        
        for(int i = 2; i<=n; i++) {
            int skip = prev;
            
            int take = nums[i-1] + prevPrev;
                
            int temp = max(skip, take);
            
            prevPrev = prev;
            prev     = temp;
        }
        
        return prev;
    }
};
