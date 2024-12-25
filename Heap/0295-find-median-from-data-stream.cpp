class MedianFinder {
public:

    // Left Max Heap - top mai badi value rehti hai
    priority_queue<int> leftMaxHeap;

    // Right Min Heap - top mai small value rehti hai
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

    // Constructor - yahaan pe koi extra initialization ki zaroorat nahi
    MedianFinder() { }

    // Ek naya number add karne ke liye function
    void addNum(int num) {

        // Agar leftMaxHeap khaali hai ya current number leftMaxHeap ke top se chhota hai,
        // toh num ko leftMaxHeap mein daal do
        if (leftMaxHeap.size() == 0 || num < leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        }
        // Nahi toh num ko rightMinHeap mein daal do
        else {
            rightMinHeap.push(num);
        }

        // Ensure karo ki leftMaxHeap ka size sirf ek greater ho rightMinHeap se
        // agar dono heaps mein size ka antar 1 se zyada ho toh adjust karo
        if (abs((int)leftMaxHeap.size() - (int)rightMinHeap.size()) > 1) {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        // Ensure karo ki rightMinHeap ka size kabhi bhi leftMaxHeap se zyada na ho
        else if (rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    // Median calculate karne ka function
    double findMedian() {
        // Agar elements ka count even hai, toh median left aur right ke top ka average hoga
        if (leftMaxHeap.size() == rightMinHeap.size()) {
            return (double)(leftMaxHeap.top() + rightMinHeap.top()) / 2;
        }
        // Agar elements ka count odd hai, toh median leftMaxHeap ka top hoga
        else {
            return leftMaxHeap.top();
        }
    }
};

