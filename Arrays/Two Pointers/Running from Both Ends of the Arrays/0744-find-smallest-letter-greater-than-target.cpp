class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Compare the characters, not casting to int (char comparison works directly)
            if (letters[mid] > target) {
                ans = mid;
                end = mid - 1;  // Search on the left side for a smaller greater element
            } else {
                start = mid + 1;  // Search on the right side for a larger element
            }
        }

        // If ans remains -1, no letter greater than target was found, return the first letter
        return (ans == -1) ? letters[0] : letters[ans];
    }
};
