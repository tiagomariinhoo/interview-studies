class MyStack {
public:

    queue<int> q, q2;

    /**
        The point here is that there's no solution that runs the Push and Pop in constant time. We need to choose one of them to run in Linear Time.

        This code runs with the Push running in O(1) but the Pop running in O(N)

        Baiscally the Queue1, is used to store the Top element always, when push a new element
        we just need to put the element that is in Queue1, into the Queue2 and put the new element into the Queue1

        When POP, we need to swap all elements into the Queue1 and do it again for Queue2, keeping just one element in Queue1
    */
    MyStack() {
        
    }
    
    void push(int x) {
        if (q.size() == 0 && q2.size() == 0) {
            q.push(x);
        } else if (q.size() != 0) {
            q2.push(q.front());
            q.pop();
            q.push(x);
        }
    }
    
    int pop() {
        int a = q.front();
        q.pop();

        while (q2.size() > 0) {
            q.push(q2.front());
            q2.pop();
        }

        while (q.size() > 1) {
            q2.push(q.front());
            q.pop();
        }

        return a;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */