class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        // Next Smaller Index (NSI) ka vector banate hain
        vector<int> nsi(n, n);
        stack<int> st; 
        st.push(n-1); 

        // NSI calculate karne ke liye backward traversal karte hain
        for(int i=n-2; i>=0; i--) {
            
            while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() == 0) nsi[i] = n;
            else nsi[i] = st.top(); 
            st.push(i); 
        }

        // Previous Smaller Index (PSI) ka vector banate hain
        vector<int> psi(n, -1);
        stack<int> gt; 
        gt.push(0); 

        // PSI calculate karne ke liye forward traversal karte hain
        for(int i=1; i<n; i++) {
            
            while(gt.size() > 0 && arr[gt.top()] >= arr[i]) gt.pop();
            if(gt.size() == 0) psi[i] = -1; 
            else psi[i] = gt.top(); 
            gt.push(i); 
        }

        int maxArea = 0; 
        for(int i=0; i<n; i++) {
            int height = arr[i]; 
            int width  = nsi[i] - psi[i] - 1; 
            int area = height * width; 
            maxArea = max(maxArea, area); 
        }
        return maxArea; 
    }
};
