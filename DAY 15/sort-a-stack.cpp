#include <bits/stdc++.h> 

void merge(stack<int>& st, int top){
	if(st.size() == 0 || st.top() < top){
		st.push(top);
		return;
	}
	int now = st.top();
	st.pop();
	merge(st, top);
	st.push(now);
}

void sortStack(stack<int> &stack)
{
	if(stack.size() == 0){
		return ;
	}
	int top = stack.top();
	stack.pop();
	sortStack(stack);
	merge(stack, top);
}