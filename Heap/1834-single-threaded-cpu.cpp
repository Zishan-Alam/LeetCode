class Solution {
public:

    typedef pair <int,int> P;   // Pair jo duration aur index ko store karega
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<int> result;                             //to return the answer
        priority_queue< P, vector<P>, greater<> > pq;   //to store the index after sorting

        //Step-01 : Store the indices 
        vector<array<int, 3>> sortedTasks;
        for(int i=0; i<n; i++) {

            int startTime = tasks[i][0];        //0 --> startTime
            int durationTime = tasks[i][1];     //1 --> durationTime
            int index = i;                      //2 --> index

            sortedTasks.push_back( {startTime, durationTime, index} );
        }

        //Step-02 : Sort the vector on the basis of startTime
        sort(sortedTasks.begin(), sortedTasks.end());

        long long int currTime = 0;     // Current time jo task processing ke sath update hoti rahegi
        int idx                = 0;     // sortedTasks ka index jo track karega kaun sa task next hai

        //Step-03 : Pushing elements into the minheap on the basis of durationTime and Index
        while( idx < n || pq.size() != 0 ) {

            if(pq.empty() && currTime < sortedTasks[idx][0]) {
                currTime = sortedTasks[idx][0];             //currTime suppose 0 hai, aur pehla task 5 baje start hoga
            }

            while( idx < n && sortedTasks[idx][0] <= currTime ) {
                pq.push( {sortedTasks[idx][1], sortedTasks[idx][2]} );  //{duration,index}
                idx++;
            }

            // Priority queue mein se duration aur index ke sath task ko nikaalte hain
            P currTask = pq.top();      //minimum duration time, then index value
            pq.pop();

            currTime += currTask.first;             //duration time
            result.push_back(currTask.second);      //index
        }

        return result;
    }
};
