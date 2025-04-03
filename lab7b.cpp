/*
b. Check whether a given graph is connected or not using DFS method.
*/
#include<iostream>
using namespace std;
int a[10][10],visit[10],n;
void dfs(int v){
    visit[v]=1;
    for(int i=0;i<n;i++)
    {
        if(a[v][i]!=0&&visit[i]==0)
        {
            cout<<v<<"->"<<i<<endl;
            visit[i]=1;
            dfs(i);
        }
    }

}
int main(){
    cout<<"enter number of vertices:\n";
    cin>>n;
    cout<<"enter matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
        visit[i]=0;
    }
    dfs(0);
    bool isconnected=true;
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        isconnected=false;
    }
    if(isconnected){
        cout<<"graph is connected\n";
    }
    else
    cout<<"graph is not connected\n";
    return 0;
}