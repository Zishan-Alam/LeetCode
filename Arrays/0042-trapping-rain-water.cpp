class Solution {
public:

    // Left side ka maximum height calculate karne wala helper function
    vector<int> getLeftMax(vector<int> &height, int &n) {
        vector<int> leftMax(n); // leftMax array jo har position par left ka maximum store karega

        leftMax[0] = height[0]; // Pehle element ka left maximum wahi height hai

        for(int i = 1; i < n; i++) {
            // Current position ka left max previous leftMax aur current height ka max hoga
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        return leftMax;
    }

    // Right side ka maximum height calculate karne wala helper function
    vector<int> getRightMax(vector<int> &height, int &n) {
        vector<int> rightMax(n); // rightMax array jo har position par right ka maximum store karega

        rightMax[n - 1] = height[n - 1]; // Last element ka right maximum wahi height hai

        for(int i = n - 2; i >= 0; i--) {
            // Current position ka right max next rightMax aur current height ka max hoga
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        return rightMax;
    }

    // Trapping water calculation ka main function
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax = getLeftMax(height, n);  // Har index ka left maximum find karte hain
        vector<int> rightMax = getRightMax(height, n); // Har index ka right maximum find karte hain

        int sum = 0; // Total trapped water

        for(int i = 0; i < n; i++) {
            // Current position par trapped water find karte hain
            int h = min(leftMax[i], rightMax[i]) - height[i];

            sum += h; // Trapped water ka total sum update karte hain
        }
        return sum; // Final trapped water return karte hain
    }
};
