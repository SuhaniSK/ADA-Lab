/*
Find Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm
*/
#include<iostream>
using namespace std;
int main(){
    int mincost=0,ne=1,n,source,visited[10],cost[10][10],a,u,b,v;
    cout<<"enter the number of vertices:\n";
    cin>>n;
    cout<<"enter the cost matrix:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        cin>>cost[i][j];
        if(cost[i][j]==0){
            cost[i][j]=999;
        }}
    }
    for(int i=1;i<=n;i++)
    visited[i]=0;
    cout<<"enter source :\n";
    cin>>source;
    visited[source]=1;
    cout<<"spanning tree:\n";
    while(ne<n){
        int min=999;
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(min>cost[i][j]){
                if(visited[i]==0)
                continue;
                else{
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
    }
    if(visited[u]==0||visited[v]==0){
        cout<<"edge:"<<ne<<":("<<a<<","<<b<<") ="<<min<<endl;
        mincost+=min;
        ne++;
        visited[b]=1;
    }
   cost[a][b]=cost[b][a]=999;
    } 
    cout<<"the cost of spanning tree is:"<<mincost<<endl;
    return 0;
}