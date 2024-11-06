// Bubble Sort
// TC : O(n*n)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        bool willSwap = true;

        for(int i=0; i<n-1; i++) {
            willSwap = false;
            for(int j=0; j<n-i-1; j++) {  //in every swap, the largest element will be placed at the last

                if(nums[j] <= nums[j+1]) {  // same elements no swapp is required
                    continue;
                }
                else {  // swap is required
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1]) ){  // swap only if have same number of set bits
                        swap(nums[j], nums[j+1]);
                        willSwap = true;
                    }
                    else{    // if swap is required but different number of set bits then array can't be sorted
                        return false;
                    }
                }
            }
            if(willSwap == false) break;
        }
        return true;
    }
};
