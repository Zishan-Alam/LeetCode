// Time Complexity: The time complexity of this solution can be analyzed based on the number of valid combinations of parentheses. 
//The number of valid combinations of n pairs of parentheses is given by the nth Catalan number, which is approximately O(4^n / n^(3/2)). 
//Therefore, the time complexity for generating all valid combinations is O(4^n / n^(3/2)). 
//Each valid combination is generated and checked for validity, which adds to the overall complexity.

//Space Complexity: The space complexity is primarily determined by the storage of the result vector and the recursion stack. 
//The result vector can store up to O(4^n / n^(3/2)) valid combinations, leading to O(4^n / n^(3/2)) space for the result. 
//Additionally, the recursion stack can go as deep as 2n (the length of the string being constructed), which contributes O(n) space. 
//Therefore, the overall space complexity is O(4^n / n^(3/2)) for the result plus O(n) for the recursion 
//stack, which simplifies to O(4^n / n^(3/2)) as the dominant term.
class Solution {
public:


    vector<string> result;

    bool isValid(string temp) {
        int count = 0;

        for(auto ch : temp) {
            if(ch == '(') {
                count++;
            }
            else{
                count--;
                if(count < 0) return false;
            }
        }
        return count == 0;
    }

    void solve(string &temp, int n) {
        if(temp.length() == 2*n) {
            if(isValid(temp)) {
                result.push_back(temp);
            }
            return;
        }

        temp.push_back("(");
        solve(temp, n);
        temp.pop_back();

        temp.push_back(")");
        solve(temp, n);
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";

        solve(temp, n);

        return result;
    }
};
