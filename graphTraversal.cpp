#include<bits/stdc++.h>
using namespace std;
//DFS ITTERATIVE
vector<char> dfs(unordered_map<char,vector<char>> &g, char source) {
	//stack is used
	vector<char> res;
	// res.push_back(source);

	stack<char> st;
	st.push(source);
	while(!st.empty()) {
		char cur=st.top();
		st.pop();
		res.push_back(cur);
		// cout<<cur<<" ";
		for(char neighbour: g[cur]) {
			st.push(neighbour);
		}
	}
	return res;
}

//DFS RECURSIVE
vector<char> res_rec;
vector<char> dfsRecursive(unordered_map<char,vector<char>> &g, char source) {
	
	res_rec.push_back(source);
	for(char neighbour: g[source]) {
		// st.push(neighbour);

		dfsRecursive(g,neighbour);
	}
	return res_rec;	
}
//BFS :- QUEUE IS USED
vector<char> bfs(unordered_map<char,vector<char>> &g, char source) {
	vector<char> res;
	queue<char> q;  //lifo
	q.push(source);
	while(!q.empty()) {
		char cur= q.front();
		q.pop();
		res.push_back(cur);
		for(char neighbour: g[cur]) {
			q.push(neighbour);
		}	
	}
	return res;
}

int main() {
	unordered_map<char,vector<char>>graph; // graph adjency list key is a node and its corresponding vector contains its neighbours
	graph['a']={'b','c'};
	graph['b']={'d'};
	graph['c']={'e'};
	graph['d']={'f'};
	graph['e']={};
	graph['f']={};

	char src='a';
	vector<char> res_dfs;
	vector<char> res_bfs;
	res_dfs=dfsRecursive(graph,src);
	res_bfs=bfs(graph,src);
	cout<<"dfs:  "<<"\t";
	for(auto i: res_dfs) {
		cout<<i<<" ";
	}
	cout<<endl;

	cout<<"bfs:  "<<"\t";
	for(auto i: res_bfs) {
		cout<<i<<" ";
	}
	cout<<endl;	

	// return 0;
}