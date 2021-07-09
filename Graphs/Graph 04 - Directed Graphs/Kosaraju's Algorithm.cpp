#include<bits/stdc++.h>
using namespace std;

// dfs1 for getting the order according to the finish time
void dfs1(vector<int> l[], int src, bool* visited, vector<int> &stack) {
    visited[src] = true;
    for (auto nbr : l[src]) {
        if (!visited[nbr]) {
            dfs1(l, nbr, visited, stack);
        }
    }
    // storing that order in the stack
    stack.push_back(src);
}

// df2 for traversing that order in reverse and printing the components
void dfs2(vector<int> l[], int src, bool* visited) {
    visited[src] = true;
    cout << src << " ";
    for (auto nbr : l[src]) {
        if (!visited[nbr]) {
            dfs2(l, nbr, visited);
        }
    }
}


int main() {

    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    vector<int> rev_adj[V];

    while (E--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        rev_adj[y].push_back(x);
    }

    bool* visited = new bool[V];
    memset(visited, 0, V);

    vector<int> stack;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(adj, i, visited, stack);
        }
    }

    char component = 'A';
    memset(visited, 0, V);
    for (int i = stack.size() - 1; i >= 0; i--) {
        if (!visited[i]) {
            cout << component << " -> ";
            dfs2(rev_adj, stack[i], visited);
            cout << endl;
        }
        component++;
    }

    return 0;
}
