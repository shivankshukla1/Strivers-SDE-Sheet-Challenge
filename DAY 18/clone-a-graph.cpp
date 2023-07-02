#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
unordered_map<graphNode*, graphNode*> m;
graphNode *cloneGraph(graphNode *node)
{
	if(!node){
		return node;
	}

	if(m.find(node) == m.end()){
		graphNode* now = new graphNode(node->data);
		m[node] = now;
		for(auto i : node->neighbours){
			now->neighbours.push_back(cloneGraph(i));
		}
	}
	
	return m[node];	
}