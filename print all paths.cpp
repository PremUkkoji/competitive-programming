#include<bits/stdc++.h>
using namespace std;

int V;

void printAllPaths(vector< vector<int> >& graph, int src, int dest, vector<bool>& visited, vector<int>& path, int path_index){
	path[path_index] = src;
	
	visited[src] = true;
	path_index++;

	if(src == dest){
		for(int i=0 ; i<path_index; i++){
			cout<<path[i]<<" ";
		}
		cout<<"\n";
	}else{
		for(int i=0;i<V;i++){
			if(graph[src][i] and !visited[i]){
				printAllPaths(graph, i, dest, visited, path, path_index);
			}
		}
	}

	path_index--;
	visited[src] = false;
}

signed main(){
	cin>>V;

	vector< vector<int> > graph(V, vector<int>(V));
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cin>>graph[i][j];
		}
	}

	int src, dest, path_index=0; 
	cin>>src>>dest;

	vector<int> path(V);
	vector<bool> visited(V, false);

	printAllPaths(graph, src, dest, visited, path, path_index);

	return 0;
}
