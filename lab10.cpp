/*
 a. Print all the nodes reachable from a given starting node in a digraph using BFS
method.
*/
#include<iostream>
using namespace std;
int indegree[10],n,cost[10][10];
void find_indegree(){
    for(int i=0;i<n;i++){
    int sum=0;
    for(int j=0;j<n;j++){
    sum+=cost[j][i];
    indegree[i]=sum;
    }}
}
void toposort(){
    int k=0,top=-1,stack[10],topo[10],u;
    find_indegree();
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        stack[++top]=i;
    }
    while (top!=-1)
    {
        u=stack[top--];
        topo[k++]=u;
        for(int i=0;i<n;i++){

            if(cost[u][i]==1){
            indegree[i]--;
            if(indegree[i]==0){
                stack[++top]=i;
            }
        }
    }
    }
    cout<<"the topological sequence is:\n";
    for(int i=0;i<n;i++)
    cout<<topo[i]<<"\t";
    cout<<endl;
    
}
int main(){
    cout<<"enter number of nodes:\n";
    cin>>n;
    cout<<"enter the matrix elements:\n";
      for(int i=0;i<n;i++){

    for(int j=0;j<n;j++){
        cin>>cost[i][j];
}}
toposort();
return 0;
}