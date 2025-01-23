//Approach-1 (Recursion with Memo) : Top Down
class Solution {
public:

    int t[46];

    int solve(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        if(t[n] != -1) return t[n];


        return t[n] = solve(n-1) + solve(n-2);
    }

    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};

//Approach-2 (Using Bottom Up DP)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        int t[n+1];
        //State Definition
        //t[i] = total ways to climb i stairs

        t[0] = 0;
        t[1] = 1;
        t[2] = 2;

        for(int i=3; i<=n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        return t[n];
    }
};

//Approach-3 : Constant Space -
//See that it looks nothing but a fibonacci sequence. You just have to store last 2 values (t[i-1] & t[i-2]) to find current value (t[i])
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        int a = 1;
        int b = 2;
        int c;

        for(int i=3; i<=n; i++) {
            c = a + b;

            a = b;
            b = c;
        }
        return c;
    }
};
