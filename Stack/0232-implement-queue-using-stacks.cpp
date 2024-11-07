class MyQueue {
public:

    stack<int> input;
    stack<int> output;

    int peekEle = -1;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()) {
            peekEle = x;
        }
        input.push(x);
    }
    
    //amortized O(1)
    int pop() {
        if(output.empty()) {
            //input --> output 0(n)
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if(output.empty()) {
            return peekEle;
        }
        else {
            return output.top();
        }
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;
        return false;
    }
};
