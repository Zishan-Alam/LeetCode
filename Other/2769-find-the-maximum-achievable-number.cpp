class Solution {
public:
    // This function calculates the maximum achievable value of 'num' after at most 't' steps.
    int theMaximumAchievableX(int num, int t) {
        // Since in each step, we can either increase or decrease 'num' by 1,
        // we can effectively increase the value of 'num' by 2 for each step if we always increase.
        // Therefore, the maximum value we can achieve is 'num + (t * 2)'.
        return (t * 2) + num;
    }
};
