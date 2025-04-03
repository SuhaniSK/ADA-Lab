#include<iostream>
using namespace std;
int max(int a,int b){
    return (a>b)?a:b;
}
int knapsack(int n,int p[],int w[],int c){
    int k[n+1][c+1];
for(int i=0;i<=n;i++){
    for(int wt=0;wt<=c;wt++){
         if(wt==0||i==0)
         k[i][wt]=0;
         else if(wt<w[i-1])
         k[i][wt]=k[i-1][wt];
         else
         k[i][wt]=max(k[i-1][wt],p[i-1]+k[i-1][wt-w[i-1]]);//in this what actually happens is for array p and w i is from 0 to n unlike for k

    }
}
cout<<endl;
for(int i=0;i<=n;i++){
    for(int wt=0;wt<=c;wt++)
cout<<k[i][wt]<<"\t";

cout<<endl;
}
return k[n][c];

}
int main(){
    int n,w[10],p[10],c;
    cout<<"enter the number of items:\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter the profit and weight for the item "<<i+1<<endl;
        cin>>p[i]>>w[i];
    }
    cout<<"enter the capacity:\n";
    cin>>c;
cout<<"the maximum profit for the following problem willl be:"<< knapsack(n,p,w,c)<<endl;
return 0;

}