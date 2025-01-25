//TWO PASS
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26, 0);
        
        for(auto ch : sentence) {
            int index = ch - 'a';
            arr[index]++;
        }

        for(auto count : arr) {
            if(count == 0) return false;
        }
        return true;
    }
};

//ONE PASS
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26, 0);
        int count = 0;

        for(auto &ch : sentence) {
            int index = ch - 'a';

            if(arr[index] == 0) {
                arr[index]++;
                count++;
            }
        }

        return count == 26;
    }
};
