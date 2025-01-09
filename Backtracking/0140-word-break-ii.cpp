class Solution {
public:

    vector<string> result;

    void solve(int i, string &s, unordered_set<string> &st, string &currSentence) {
        if(i >= s.length()) {
            result.push_back(currSentence);
            return;
        }

        for(int j=i; j<s.length(); j++) {

            string tempWord = s.substr(i, j-i+1);

            if(st.count(tempWord)) {

                string tempSentence = currSentence;     //storing

                if(!currSentence.empty()) {
                    currSentence += " ";
                }

                currSentence += tempWord;               //Do

                solve(j+1, s, st, currSentence);        //Explore

                currSentence = tempSentence;            //Undo
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string currSentence = "";
        unordered_set<string> st;

        for(auto &it : wordDict) {
            st.insert(it);
        }

        solve(0, s, st, currSentence);

        return result;
    }
};
