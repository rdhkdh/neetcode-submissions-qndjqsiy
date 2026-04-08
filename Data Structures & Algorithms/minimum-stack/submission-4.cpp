class MinStack {
public:
    vector<int> v; //min so far prefix array
    int min_so_far = INT_MAX;
    stack<int> s;

    MinStack() {
        min_so_far = INT_MAX;
    }
    
    void push(int val) {
        s.push(val);
        min_so_far = min(min_so_far, val);
        v.push_back(min_so_far);
    }
    
    void pop() {
        s.pop();
        v.pop_back();
        if(v.empty()) {min_so_far = INT_MAX;}
        else{min_so_far = *v.rbegin();}
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *v.rbegin();
    }
};
