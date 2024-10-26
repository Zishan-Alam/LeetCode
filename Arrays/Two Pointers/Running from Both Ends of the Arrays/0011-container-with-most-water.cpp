class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n-1;

        int maxWater = 0;

        while(i < j) {
            int w = j-i;
            int h = min(height[i],height[j]);
            int area = w*h;

            maxWater = max(maxWater, area);

            if(height[i] > height[j]) j--; //to maximise area, apan width to automatically kam karhe hai, bas to increase height
            else i++;                      // we are ensuring ki max height vala element still contribute karein !
        }
        return maxWater;
    }
};
