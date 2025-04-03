#include<iostream>
#define infinity 999
using namespace std;
void dij(int n,int v,int dist[10],int cost[10][10]){
    int flag[10],u,count;
    for(int i=0;i<n;i++)
    flag[i]=0,dist[i]=cost[v][i];
    flag[v]=1;
    count=1;
    while(count<n){
        int min=99;
        for(int i=0;i<n;i++){
            if(dist[i]<min&&!flag[i])
            min=dist[i],u=i;
        }
        flag[u]=1;
        count++;
        for(int w=0;w<n;w++)
        if(dist[u]+cost[u][w]<dist[w]&&!flag[w])
        dist[w]=dist[u]+cost[u][w];    
     }
}
int main(){
    int n,v,dist[10],cost[10][10];
    cout<<"enter number of nodes:\n";
    cin>>n;
    cout<<"enter the cost matrix:\n";
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin>>cost[i][j];
        if(cost[i][j]==0&&i!=j)
        cost[i][j]=infinity;
    }
    cout<<"enter source vertex\n";
    cin>>v;
    dij(n,v,dist,cost);
    for(int i=0;i<n;i++){
        if(i!=v)
        cout<<v<<"->"<<i<<",cost="<<dist[i]<<endl;
    }
    return 0;
}