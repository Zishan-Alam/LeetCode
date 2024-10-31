// Time Complexity: O(n log n) where n --> number of digits in number
// Space Complexity: O(n) where n --> number of digits in number

class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> evenHeap;
        priority_queue<int> oddHeap;

        string s = to_string(num);

        for(auto ch : s) {
            int ele = ch - '0';

            if(ele % 2 == 0) evenHeap.push(ele);
            else oddHeap.push(ele);
        }

        string ans = "";

        for(auto &ch : s) {
            int ele = ch - '0';

            if(ele % 2 == 0) ans += to_string(evenHeap.top()), evenHeap.pop();
            else ans += to_string(oddHeap.top()), oddHeap.pop();

        }
        return stoi(ans);
    }
};
