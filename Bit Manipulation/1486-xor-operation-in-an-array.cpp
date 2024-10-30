// Time Complexity: O(2n) Iterating two times in an array
// Space Complexity: O(n)

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr(n);
        int ans = 0;

        for(int i=0; i<n; i++) {
            arr[i] = start + (2 * i);
        }
        for(int i=0; i<n; i++) {
            ans ^= arr[i];
        }
        return ans;
    }
};

// Time Complexity: O(n) Iterating only one time in an array
// Space Complexity: O(1)

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;

        for(int i=0; i<n; i++) {
            ans ^= (start + (2 * i) ); 
        }
        return ans;
    }
};
