// TC : 0(nlogn)
// SC : 0(1)
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);

            if(countA == countB) return a < b;

            return countA < countB;
        });
        return arr;
    }
};

// Lambda function written outside of the function
class Solution {
public:

    static auto compare(int a, int b) {
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);

        return (countA == countB)? a < b : countA < countB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
