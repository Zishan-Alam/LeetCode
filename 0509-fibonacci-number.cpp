class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;  // Base case: F(0) = 0
        if (n == 1) return 1;  // Base case: F(1) = 1
        
        int a = 0;  // F(0)
        int b = 1;  // F(1)
        
        for (int i = 2; i <= n; i++) {
            int c = a + b;  // F(i) = F(i-1) + F(i-2)
            a = b;
            b = c;
        }
        
        return b;  // F(n)
    }
};
