class Solution {
public:
    // Function to compute the next permutation of a string 'num'
    void nextPermutation(string& num) {
        int n = num.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && num[i] >= num[i + 1]) {
            i--;
        }

        // Step 2: Find the next larger element and swap
        if (i >= 0) {
            int j = n - 1;
            while (num[j] <= num[i]) {
                j--;
            }
            swap(num[i], num[j]);
        }

        // Step 3: Reverse the suffix to get the next permutation
        reverse(num.begin() + i + 1, num.end());
    }

    // Function to get the minimum number of adjacent swaps to get the k-th
    // permutation
    int getMinSwaps(string num, int k) {
        string original = num;

        // Generate the k-th permutation
        while (k--) {
            nextPermutation(num);
        }

        // Now, count the minimum number of adjacent swaps needed to convert
        // 'original' to 'num'
        int swaps = 0;
        for (int i = 0; i < original.size(); i++) {
            if (original[i] != num[i]) {
                // Find the position in 'original' where num[i] occurs and swap
                // to move it to the correct position
                int j = i;
                while (original[j] != num[i]) {
                    j++;
                }

                // Move original[j] to original[i] by adjacent swaps
                while (j > i) {
                    swap(original[j], original[j - 1]);
                    j--;
                    swaps++;
                }
            }
        }

        return swaps;
    }
};
