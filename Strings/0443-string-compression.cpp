class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0;          // to iterate over the chars
        int index = 0;      // for assigning the value

        while(i < n) {

            char curr = chars[i];
            int count = 0;

            // Step:01 - finding the count of chars
            while(i < n && chars[i] == curr) {
                i++;
                count++;
            }

            // Step:02 - assigning the count of chars
            chars[index] = curr;                //char
            index++;
            
            if(count > 1) {
                string count_str = to_string(count);
                for(auto &ch : count_str) {
                    chars[index] = ch;          //times
                    index++;
                }
            }
        }
        return index;
    }
};
