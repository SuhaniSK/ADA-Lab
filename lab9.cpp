#include<iostream>
#include<algorithm>
using namespace std;
void floyd(int a[10][10],int n){
for(int k=0;k<n;k++)
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout<<a[i][j]<<" ";
}
cout<<endl;
}}
int main(){
    int a[10][10],n;
    cout<<"enter the number of nodes:\n";
    cin>>n;
    cout<<"enter the matrix elements\n";
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j];
   
    cout<<" the solution for the shortest path using floyds algorithm\n";
 floyd(a,n);
 return 0;
}