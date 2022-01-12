// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool issafe(bool graph[101][101],vector<int> &colors,int node,int color){
    for(int i=0;i<colors.size();i++){
        if(graph[node][i] and colors[i]==color){
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101],vector<int> &colors,int node, int n,int m){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(issafe(graph,colors,node,i)){
            colors[node]=i;
            if(solve(graph,colors,node+1,n,m)){
                return true;
            }
            colors[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colors(V,0);
    return solve(graph,colors,0,V,m);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends