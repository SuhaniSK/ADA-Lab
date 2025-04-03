/*
Implement any scheme to find the optimal solution for the Traveling Salesperson
problem and then solve the same problem instance using any approximation algorithm
and determine the error in the approximation.
*/
#include<iostream>
using namespace std;
int n,cost[10][10],visit[10],cost_apr=0,cost_opt=0;
int least_opt(int c){
    int nc=999,min=999,kmin=999;
    for(int i=1;i<=n;i++){
        if(cost[c][i]!=0&&visit[i]==0)
         {  if(cost[c][i]<min){
            min=cost[i][1]+cost[c][i];
            nc=i;
            kmin=cost[c][i];
         }}
        }
        if(nc!=999){
            cost_opt+=kmin;
        }
        return nc;
    
}
int least_apr(int c){
    int nc=999,min=999,kmin=999;
    for(int i=1;i<=n;i++){
        
         if(cost[c][i]!=0&&visit[i]==0)
         {  if(cost[c][i]<kmin){
            min=cost[i][1]+cost[c][i];
            nc=i;
            kmin=cost[c][i];
         }}
        }
        if(nc!=999){
            cost_apr+=kmin;
        }
        return nc;
}
void mincostopt(int city){
    int i,ncity;
    visit[city]=1;
    cout<<city<<"-->";
    ncity=least_opt(city);
    visit[ncity]=1;
    if(ncity==999){
        ncity=1;
        cout<<ncity;
        cost_opt+=cost[city][ncity];
        return;
    }
    mincostopt(ncity);

}
void mincostapr(int city){
    int i,ncity;
    visit[city]=1;
    cout<<city<<"-->";
    ncity=least_apr(city);
    visit[ncity]=1;
    if(ncity==999){
        ncity=1;
        cout<<ncity;
        cost_apr+=cost[city][ncity];
        return;
    }
    mincostapr(ncity);

}
int main(){
    cout<<"enter number of cities:\n";
    cin>>n;
    cout<<"enter the cost matrix:\n";
    for(int i=1;i<=n;i++){
        cout<<"enter the ekements for row "<<i<<endl;
        for(int j=1;j<=n;j++)
        cin>>cost[i][j];
        visit[i]=0;
    }
    cout<<"the cost matrix is:\n";
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        cout<<cost[i][j]<<"\t";
        cout<<endl;
     }
     cout<<"the optimal solution path:\n";
     mincostopt(1);
     cout<<endl;
     cout<<"the minimum optimal cost:"<<cost_opt<<endl;
     // Resetting visit array for the approximation run
     for (int i = 1; i <= n; i++)
     visit[i] = 0;

     cout<<"the approximate solution path:\n";
     mincostapr(1);
     cout<<endl;
     cout<<"the minimum approx cost:"<<cost_apr<<endl;

     cout<<"the error is approx/optimal :"<<(float)(cost_apr)/(cost_opt)<<endl;
     return 0;

}