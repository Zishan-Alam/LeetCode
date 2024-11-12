// Brute Force
// TC : 0(m*n) where m --> is the size of the query, n --> is the size of array
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        int m = items.size();

        vector<int> result(n);

        for(int i=0; i<n; i++) {
            int maxi = INT_MIN;
            int query = queries[i];

            for(int j=0; j<m; j++) {

                int price  = items[j][0];
                int beauty = items[j][1];

                if(price <= query) {
                    maxi = max(maxi, beauty);
                }
            }
            result[i] = (maxi == INT_MIN) ? 0 : maxi;
        }
        return result;
    }
};

// Optimal using Binary Search
// TC : O(mlogn + nlogn)
class Solution {
public:

    int bSearch(vector<vector<int>> &items, int query) {    //O(logn)
        int start = 0;
        int end   = items.size()-1;

        int maxBeauty = 0;

        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(items[mid][0] > query) {
                end = mid - 1;
            }
            else{
                maxBeauty = max(maxBeauty, items[mid][1]);
                start = mid+1;
            }
        }
        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<int> result(m);

        //Step - 01 : Sort the array based on the price
        sort(begin(items), end(items)); // it will by default sort on the basi of first element

        int maxBeautySeen = items[0][1];
        for(int i=1; i<n; i++) {        //O(nlogn)
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }

        for(int i=0; i<m; i++) {        //O(mlogn)
            int query = queries[i];
            result[i] = bSearch(items, query);
        }
        return result;
    }
};
