//Approach-1 (Using Simple LIS recursion+memo) - Since Qn asks to take pairs in any order, we sort it in the beginning
class Solution {
public:

    int t[1001][1001];

    int lis(vector<vector<int>>& pairs, int prevIdx, int idx, int n) {
        if(idx == n) return 0;

        int take = 0;

        if(prevIdx != -1 && t[prevIdx][idx] != -1) return t[prevIdx][idx];

        if(prevIdx == -1 || pairs[prevIdx][1] < pairs[idx][0]) {
            take = 1 + lis(pairs, idx, idx+1, n);
        }
        int skip = lis(pairs, prevIdx, idx+1, n);

        if(prevIdx != -1) t[prevIdx][idx] = max(take, skip);

        return max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();
        memset(t, -1, sizeof(t));

        return lis(pairs, -1, 0, n);
    }
};

//Approach-2 (Using Simple LIS Bottom Up) - Since Qn asks to take pairs in any order, we sort it in the beginning
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        vector<int> t(n, 1);
        int maxLIS = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    t[i] = max(t[i], t[j] + 1);
                    maxLIS = max(maxLIS, t[i]);
                }
            }
        }
        return maxLIS;
    }
};
