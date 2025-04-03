/*
b. Check whether a given graph is connected or not using DFS method.
*/
#include<iostream>
using namespace std;

int main(){
int a[10][10],n;
cout<<"enter the number of vertices:\n";
cin>>n;
cout<<"enter the adjacency matrix(1:edge is present 0:no edge)\n";
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
cin>>a[i][j];
for(int k=0;k<n;k++)
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
cout<<"the transitive closure is\n:";
for(int i=0;i<n;i++){
for(int j=0;j<n;j++)
cout<<a[i][j]<<"\t";
cout<<endl;
}
return 0;
}