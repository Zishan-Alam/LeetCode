//Approach-1 (TopDown: Recur+Memo) 
//T.C : O(n*n)
class Solution {
public:
    int t[2501][2501];
    int lis(vector<int> &nums, int prevIdx, int idx, int n) {
        if(idx == n) return 0;

        if(prevIdx != -1 && t[prevIdx][idx] != -1) return t[prevIdx][idx];      //p != -1 coz it will break the memoize t[i][p]

        int take = 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[idx]) {
            take = 1 + lis(nums, idx, idx+1, n);
        }

        int skip = lis(nums, prevIdx, idx+1, n);

        if(prevIdx != -1) t[prevIdx][idx] = max(take, skip);
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        return lis(nums, -1, 0, n);
    }
};

//Approach-2 (Bottom Up DP) O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, 1);
        //State Definition
        //t[i] --> LIS till ith index

        int maxLIS = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j] + 1);
                    maxLIS = max(maxLIS, t[i]);
                }
            }
        }
        return maxLIS;
    }
};
