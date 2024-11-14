class Solution {
public:

    bool possibleToDistribute(int x, vector<int> quantities, int shops) {
        for(auto &prod : quantities) {

            shops -= (prod + x - 1)/x;      //ceil(product/x)

            if(shops < 0) return false;

        }
        return true;
    }

    int maximumElement(vector<int> &quantities) {
        int maxi = INT_MIN;
        for(auto it : quantities) {
            if(it > maxi) maxi = it;
        }
        return maxi;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        int start = 1;
        int end   = maximumElement(quantities);

        int result = 0;

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(possibleToDistribute(mid, quantities, n)) {
                result = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return result;
    }
};
