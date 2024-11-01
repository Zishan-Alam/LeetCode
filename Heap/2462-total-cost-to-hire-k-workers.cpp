// Time complexity is O(k log candidates) where k --> number of workers to be hired
// Space complexity is O(candidates).
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> front;   //minheap
        priority_queue<int, vector<int>, greater<int>> back;    //minheap
        long long int totalCosts = 0;

        int i = 0; 
        int j = n - 1; 

        while(k != 0) { // k iterations tak loop chalega

            // Front heap ko candidates elements tak bharte hain
            while(front.size() < candidates && i <= j) {
                front.push(costs[i]); // front queue mein costs ke starting se elements push karna
                i++; // i ko increment karna
            }

            // Back heap ko bhi candidates elements tak bharte hain
            while(back.size() < candidates && j >= i) {
                back.push(costs[j]); // back queue mein costs ke end se elements push karna
                j--; // j ko decrement karna
            }

            int minFront = (front.size() > 0) ? front.top() : INT_MAX; // front heap ka minimum ya agar empty ho toh INT_MAX
            int minBack = (back.size() > 0) ? back.top() : INT_MAX; // back heap ka minimum ya agar empty ho toh INT_MAX

            // Dono minimums mein se chhoti value totalCosts mein add karte hain aur usi heap se pop karte hain
            if(minFront <= minBack) {
                totalCosts += minFront; // front heap ka minimum add karna
                front.pop(); // front heap se minimum element ko pop karna
            }
            else {
                totalCosts += minBack; // back heap ka minimum add karna
                back.pop(); // back heap se minimum element ko pop karna
            }
            k--; // k ko decrement karte hain, yani ab ek cost aur chahiye
        }
        return totalCosts; // final cost 
    }
};
