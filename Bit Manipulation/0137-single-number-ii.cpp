// Bit Manipulation Approach
// TC : 0(32n)
// SC : 0(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(int k=0; k<32; k++){
            int temp = (1 << k);
          
            int countOnes = 0;

            for(auto &num : nums){
                if( (num & temp) == temp) countOnes++;
            }
            if(countOnes % 3 == 1) result = result | temp;
        }
        return result;
    }
};

// Sorting Approach
// TC : 0(nlogn)
// SC : 0(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Traverse the array in steps of 3
        for (int i = 0; i < n - 1; i += 3) {
            // If the current element doesn't match the next 
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        
        // If unique element is at the last position
        return nums[n - 1];
    }
};
