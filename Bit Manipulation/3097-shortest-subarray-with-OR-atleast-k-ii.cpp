class Solution {
public:

    // Yeh function window mein number ke bit set count ko update karta hai
    // 'vec' mein bit position ko increment ya decrement karta hai 'val' ke hisaab se
    void updateInWindow(int number, vector<int> &vec, int val) {
        for(int i=0; i<32; i++) {
            if( (number >> i) & 1 ) {
                vec[i] += val;
            } 
        }
    }

    // Yeh function 'vec' se decimal number banata hai
    // Agar kisi bit position par count greater than 0 hai toh uss bit ko set karta hai
    int getDecimalNumber(vector<int> vec) {
        int num = 0;

        for(int i=0; i<32; i++) {
            if(vec[i] > 0) {
                num |= (1 << i);
            }
        }
        return num;
    }

    // Minimum subarray ki length find karta hai jiska bitwise OR result 'k' ya usse bada ho
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int result = INT_MAX;  // Minimum length ko track karta hai

        int i=0; 
        int j=0;

        vector<int> vec(32,0);  // Bit set count ko track karne ke liye 32 size ka vector

        while(j < n) {
            updateInWindow(nums[j], vec, 1);  // vec[i] mein ith position par total set bits ka count store karta hai

            // Jab tak window ka OR result 'k' ya usse bada hai, tab tak length ko update karta hai aur window ke starting point ko shift karta hai
            while(i <= j && getDecimalNumber(vec) >= k) {
                result = min(result, j-i+1);  // Minimum length ko update karta hai
                updateInWindow(nums[i], vec, -1);  // Window ke start se bit set ko decrement karta hai
                i++;
            }
            j++;
        }
        return (result == INT_MAX) ? -1 : result;  // Agar subarray nahi mila toh -1 return karta hai, warna minimum length
    }

};
