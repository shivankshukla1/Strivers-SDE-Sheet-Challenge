#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		stack<int> st, mini;

		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			st.push(num);
			if(mini.size() == 0 || mini.top() >= num){
				mini.push(num);
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.size() == 0){
				return -1;
			}

			int top = st.top();
			st.pop();
			if(mini.size() && mini.top() == top){
				mini.pop();
		
			}
			return top;		// Write your code here.
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.size() == 0){
				return -1;
			}
			return st.top();
				// Write your code here.
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(mini.size()){
				return mini.top();
			}
			return -1;
			// Write your code here.
		}
};