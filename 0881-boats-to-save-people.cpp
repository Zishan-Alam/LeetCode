class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the people by their weights
        sort(people.begin(), people.end());

        int i = 0;
        int j = people.size() - 1;
        int count = 0;

        // Two-pointer approach
        while (i <= j) {
            // Check if the lightest and heaviest person can share the boat
            if (people[i] + people[j] <= limit) {
                i++; // Lightest person is paired with heaviest
            }
            // In both cases, the heaviest person always takes the boat
            j--;
            count++; // Increase boat count
        }

        return count;
    }
};
