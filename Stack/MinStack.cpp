#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
    stack<int> st,pre;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            pre.push(val);
        }
        else{
            st.push(val);
            pre.push(min(pre.top(),val));
        }
    }
    
    void pop() {
        st.pop();
        pre.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
       return pre.top(); 
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