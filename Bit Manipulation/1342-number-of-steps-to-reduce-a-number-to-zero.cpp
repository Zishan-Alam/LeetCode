// Iterative Approach
// TC : 0(logn) because in each iteration, we are dividing the number or making it smaller
// SC : 0(1)
class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;

        while(num !=0) {
            if( (num % 2) == 0 ) num = num / 2; 
            else num = num - 1;
            steps++;
        }
        return steps;
    }
};

//Recursive Approach
// Time Complexity: O(log(num))
// Space Complexity: O(log(num))
class Solution {
public:

    int sum = 0;
    int numberOfSteps(int num) {
        if(num == 0) return sum;
        sum++;
        
        if(num % 2 == 0) numberOfSteps(num/2);
        else numberOfSteps(num-1);
        return sum;
    }
};

//Bitwise Approach
// TC : 0(logn)
// SC : 0(1)
class Solution {
public:
    int numberOfSteps(int num) {
        if( num == 0) return 0;
        int steps = 0;

        while(num != 0) {
            steps += ( (num % 2) == 0)? 1 : 2;
            num >>= 1;
        }
        return steps-1;
    }
};


