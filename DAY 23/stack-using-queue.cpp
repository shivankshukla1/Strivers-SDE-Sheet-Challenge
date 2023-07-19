class Stack {
	// Define the data members.
    queue<int> st;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return st.size();
    }

    bool isEmpty() {
        return st.size() == 0;
        // Implement the isEmpty() function.
    }

    void push(int element) {
        st.push(element);
        for(int i =0; i < st.size() - 1; i++){
            int top1 = st.front();
            st.pop();
            st.push(top1);
        }
        // Implement the push() function.
    }


    int pop() {
        if(st.size() == 0){
            return -1;
        }
        int answer = st.front();
        st.pop();
        return answer;
        // Implement the pop() function.
    }

    int top() {
                if(st.size() == 0){
            return -1;
        }
        return st.front();
        // Implement the top() function.
    }
};