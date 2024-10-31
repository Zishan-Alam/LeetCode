// Sorting
// TC : O(nlogn)
// SC : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};

// Heap
// TC : O(nlogn)
// SC : O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto &it : nums) pq.push(it);

        int largest = pq.top(); pq.pop();
        int slargest = pq.top(); pq.pop();

        return (largest-1)*(slargest-1);
    }
};
// TC : O(n)
// TC : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;   // Maximum element
        int smaxi = INT_MIN;  // Second maximum element

        // Single loop mein maxi aur smaxi calculate karte hain
        for (auto &it : nums) {
            if (it > maxi) {
                smaxi = maxi;  // Previous maxi ko smaxi banate hain
                maxi = it;     // New maxi set karte hain
            } else if (it > smaxi) {
                smaxi = it;    // Second maximum set karte hain
            }
        }

        // Problem ke hisaab se answer return karte hain
        return (maxi - 1) * (smaxi - 1);
    }
};

