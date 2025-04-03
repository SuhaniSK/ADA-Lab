/*
a. Print all the nodes reachable from a given starting node in a digraph using BFS
method.
*/
#include<iostream>
using namespace std;
int a[10][10],n,visit[10],s,queue[10],front=0,rear=-1,flag=0;
void insert(int v){
    queue[++rear]=v;
}
int del(){
    return queue[front++];
}
int qempty(){
    return rear<front;
}
void bfs(int s){
    visit[s]=1;
    insert(s);
    while(!qempty()){
        s=del();
    for(int i=0;i<n;i++){
    if(a[s][i]!=0&&visit[i]==0){
        visit[i]=1;
        cout<<"v"<<i<<endl;
        flag=1;
    insert(i);
    }    }}
}
int main(){
    cout<<"enter thr number of vertices\n";
    cin>>n;
    cout<<"enter the adjacency matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
        visit[i]=0;
        

    }
    cout<<"enter the source vertex\n";
    cin>>s;
    cout<<"the visitability vertex:\n";
    bfs(s);
    if(flag==0){
        cout<<"no path\n";
    }
    return 0;

}
/*
enter the number of nodes:
4
enter the cost matrix:
0 1 1 0 
1 0 0 0
1 1 0 1
0 0 1 0
enter the source vertex(node):
0
the reachability vertex:
v1
v2
v3
*/