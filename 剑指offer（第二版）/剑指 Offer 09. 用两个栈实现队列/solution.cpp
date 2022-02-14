class CQueue {
private:
    stack<int> stk1, stk2;

public:
    CQueue() {
        while (!stk1.empty()) {
            stk1.pop();
        }
        while (!stk2.empty()) {
            stk2.pop();
        }
    }

    void appendTail(int value) {
        stk1.push(value);
    }

    int deleteHead() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        
        if (stk2.empty()) {
            return -1;
        } else {
            int value = stk2.top();
            stk2.pop();
            return value;
        }
    }
};