class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Pointers initialize 
        int i = m - 1;      // nums1 ke shuruat ke last element ka index
        int j = n - 1;      // nums2 ke last element ka index
        int k = m + n - 1;  // merged nums1 ke last element ka index

        // nums1 aur nums2 ko end se merge kar rahe hain
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) { // Agar nums1 ka current element bada hai
                nums1[k] = nums1[i];
                i--;
                k--;
            } else {                  // Agar nums2 ka current element bada ya barabar hai
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        // Agar nums1 mein koi elements nahi bache hain, to nums2 ke remaining elements ko nums1 mein copy karte hain
        if(i < 0) {
            while(j >= 0) {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        // Agar nums2 mein koi elements nahi bache hain, to nums1 ke remaining elements already place mein hain
        if(j < 0) {
            while(i >= 0) {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }
    }
};
