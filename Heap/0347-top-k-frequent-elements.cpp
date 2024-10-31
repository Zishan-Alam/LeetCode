//Bucket Sort Approach
//Time complexity is O(n)
//Space complexity is O(n).
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        //Step-01 : Storing frequency in map
        unordered_map<int,int> mp;
        for(auto &it : nums) mp[it]++;

        //Step-02 : Storing elements on bucket on the basis of frequency
        vector< vector<int> > bucket(n+1);
        //Index     --> frequency
        //Value     --> elements
        //bucket[i] --> elements having `i` frequency

        for(auto &it : mp) {
            int element     = it.first;
            int frequency   = it.second;

            bucket[frequency].push_back(element);
        }

        //Step-03 : Storing the result
        vector<int> result;
        for(int i=n; i>=0; i--) {
            if(bucket[i].size() == 0) continue;

            while(bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};

//Using Min Heap
//Time complexity is O(n + m log k).    (k --> top frequent elements, m --> number of unique elements in map)
//Space complexity is O(n + k).         (k --> top frequent elements in heap, n --> elements in map)
class Solution {
public:

    typedef pair<int,int> P;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Step-01 : Map 
        unordered_map<int,int> mp;
        for(auto &it : nums) mp[it]++;

        //Step-02 : Min Heap
        priority_queue<P, vector<P>, greater<P>> pq;
        for(auto &it : mp) {
            pq.push( {it.second, it.first} );

            if(pq.size() > k) pq.pop();
        }

        //Step-03 : Storing the answer
        vector<int> result;
        while( !pq.empty() ) {
            result.push_back( pq.top().second );
            pq.pop();
        }
        return result;
    }
};


//Using Max Heap
//Time complexity is O(n log n).
//Space complexity is O(n) due to the frequency map and the priority queue
class Solution {
public:
    typedef pair<int,int> P;

    struct lambda{
        bool operator()(P &p1, P &p2) {
            return p1.second < p2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<P, vector<P>, lambda> pq;
        unordered_map<int,int> mp;
        vector<int> result;

        for(auto it : nums) mp[it]++;                           //O(n) space for map

        for(auto it : mp) pq.push( {it.first, it.second} );     //O(k) space for heap

        while( k != 0 ) {                       //O(k) time
            P temp = pq.top();
            pq.pop();

            result.push_back(temp.first);       //O(logn) for rearranging the heap elements
            k--;
        }
        return result;
    }
};
