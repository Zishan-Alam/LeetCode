//time complexity is O(n^2) and the space complexity is O(1).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int diff = prices[j] - prices[i];
                maxi = max(maxi, diff);
            }
        }
        return maxi;
    }
};

//time complexity is O(n) and the space complexity is O(n).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> future(n);  //store the max in future elements

        //filling the future array
        future[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            future[i] = max(future[i+1], prices[i]);
        }

        int ans = 0;
        //Calculating the ans array
        for(int i=0; i<n; i++) {
            int diff = future[i] - prices[i];
            ans = max(ans, diff);
        }
        return ans;
    }
};

//time complexity is O(n) and the space complexity is O(1).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;
        int minSoFar = prices[0];

        for(int i=0; i<n; i++) {
            minSoFar = min(minSoFar, prices[i]);
            int profit = prices[i] - minSoFar;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
