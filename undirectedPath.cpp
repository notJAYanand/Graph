#include<bits/stdc++.h>
using namespace std;


//concert into adj list
unordered_map<char,vector<char>> convert(vector<vector<char>> &edges) {
	unordered_map<char,vector<char>>graph;
	for(auto edge : edges) {
		vector<char> e= {edge[0],edge[1]};
		if(!(graph.find(e[0])!=graph.end())) {
			graph[e[0]]={};
		}
		if(!(graph.find(e[1])!=graph.end())) {
			graph[e[1]]={};
		}		
		graph[e[0]].push_back(e[1]);
		graph[e[1]].push_back(e[0]);
	}
	return graph;
}
//DFS recursive
bool hasPath(unordered_map<char,vector<char>>&graph,char src, char dest,unordered_set<char> visited) {

	if(src==dest) return true;
	if(visited.find(src)!=visited.end())
	{
		return false;
	}
	visited.insert(src);	
	for(auto neighbour : graph[src]) {
		if(hasPath(graph,neighbour,dest,visited))
		{
			return true;
		}
	}
	return false;
}


int main() {
	// unordered_map<char,vector<char>>graph; // graph adjency list key is a node and its corresponding vector contains its neighbours (un directed)
	// graph['a']={'b','c'};
	// graph['b']={'a' ,'d','c'}; // undirected has reversed connections too.
	// graph['c']={'a','e','b'}; //this graph has cycle a-b-c which can create infinite loop
	// graph['d']={'f'};
	// graph['e']={'c'};
	// graph['f']={'d'};
	vector<vector<char>> edges= {
		{'i','j'},
		{'k','i'},
		{'m','k'},
		{'k','l'},
		{'o','n'},

	};
	unordered_map<char,vector<char>>graph=convert(edges);
	unordered_set<char> visited;
	cout<<hasPath(graph,'o', 'k',visited)<<endl;
	// for(auto i: graph)
	// {
	// 	// cout<<i.first<<endl;
	// }
	// for(auto i : graph['k'])
	// {
	// 	cout<<i<<endl;
	// }
	// return 0;
}