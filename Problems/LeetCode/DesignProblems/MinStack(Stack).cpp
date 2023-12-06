class MinStack {
public:

    /**
        We can solve this problem by implementing a Stack using a Linked List.

        Basically we just need to implement the normal linked list but for each Node,
        u need to store the Min value that we have in the stack until now. So we can find it in O(1)
    */

    struct Node {
        int val;
        int min;
        Node *next;
    };

    Node *head = NULL;

    MinStack() {
    }
    
    void push(int val) {
        Node *aux = new Node();
        aux->val = val;
        aux->min = val;

        if (head != NULL && head->min < val) {
            aux->min = head->min;
        }

        aux->next = head;
        head = aux;
    }
    
    void pop() {
        if (head != NULL) {
            head = head->next;
        }
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */