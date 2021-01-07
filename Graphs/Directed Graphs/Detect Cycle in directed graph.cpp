#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int>* l,int src,bool* visited,bool* stack){
	visited[src]=true;
	stack[src]=true;

	for(auto nbr:l[src]){
		// if not visited then proceed with nbr calls
		if(!visited[nbr]){
			if(dfs(l,nbr,visited,stack))
				return true;
		}
		// if its visited and its in the path of current node
		else if(stack[nbr]){
			return true;
		}
	}
	
	stack[src]=false;
	return false;
}

int main(){
	int v,e;
	cin>>v>>e;
	
	vector<int> l[v];

	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		l[a].push_back(b);
	}

	bool* visited = new bool[v];
	bool* stack = new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
		stack[i]=false;
	}
    
    int i;
	for(i=0;i<v;i++){
        if(dfs(l,i,visited,stack)){
            cout<<"Cycle is Present"<<endl;
            break;
        }
        if(i==v) cout<<"Cycle is not Present"<<endl;   
	}
	return 0;
}