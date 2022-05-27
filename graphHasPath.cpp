#include<bits/stdc++.h>
using namespace std;
//hasPath whether we can travel feom source to dest in directed graph (graph is always acyclic)
//using recursion (DFS)


bool hasPath(unordered_map<char,vector<char>>&g,char src , char dest) {
	if(src==dest) return true;
	for(char neighbour: g[src]) {
		if(hasPath(g,neighbour,dest)==true) {
			return true;
		}
	}
	return false;		
}


bool hasPath(unordered_map<char,vector<char>>&g,char src , char dest,char bfs) { //overloaded for convinience sake with a dummy parameter "char bfs"
	queue<char> q;
	q.push(src);
	while(!q.empty()) {
		char cur= q.front();
		q.pop();
		if(cur==dest) return true;

		for(char neighbour: g[cur]) {
			q.push(neighbour);
		}	
	}
	return false;
}


int main() {
	unordered_map<char,vector<char>>graph; // graph adjency list key is a node and its corresponding vector contains its neighbours
	graph['a']={'b','c'};
	graph['b']={'d'};
	graph['c']={'e'};
	graph['d']={'f'};
	graph['e']={};
	graph['f']={};

	cout<<hasPath(graph,'a','e')<<endl; //using dfs
	cout<<hasPath(graph,'a','e','$')<<endl; //using bfs

}