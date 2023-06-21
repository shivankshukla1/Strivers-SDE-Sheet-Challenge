#include <bits/stdc++.h>
priority_queue<int> first;
priority_queue<int, vector<int>, greater<int>> second;

void add(int n){
	first.push(n);
	second.push(first.top());
	first.pop();
	if(second.size() > first.size()){
		first.push(second.top());
		second.pop();
	}
}

int find(){
	if(first.size() == second.size()){

		return (first.top() + second.top())/2;
	}else{
		return first.top();
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> answer;
	while(first.size()){
		first.pop();
	}
	while(second.size()){
		second.pop();
	}
	for(auto i : arr){
		add(i);
		answer.push_back(find());
	}

	return answer;	
}
