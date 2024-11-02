// Time complexity is O(n log k) where n --> number of elements in points vector
// Space complexity is O(k).
class Solution {
public:

    typedef pair<int, vector<int>> P;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<P> pq;    //maxheap
        for(auto &point : points) {
            int x = point[0];
            int y = point[1];

            int distance = x*x + y*y;

            pq.push({distance, {x, y}}); //can also be written as pq.push({dist, point});

            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> result;

        while( !pq.empty() ) {
            P temp = pq.top();
            pq.pop();

            int x = temp.second[0];
            int y = temp.second[1];

            result.push_back( {x,y} );
        }
        return result;
    }
};
