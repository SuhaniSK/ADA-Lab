#include <iostream>
using namespace std;
int main() {
    int ne = 1, mincost = 0, n, i, j, min, u, v, a, b;
    int cost[20][20], parent[20];
    cout << "Enter the number of vertices:\n";
    cin >> n;
    cout << "Enter the cost matrix:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> cost[i][j];
            // Use a large number for no connection
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Treat zero cost as infinite
            }
        }
    }
   for (i = 1; i <= n; i++) {
        parent[i] = 0;
    }
    cout << "The edges of the spanning tree are:\n";
    while (ne < n) {
        min = 999;
        // Find the minimum cost edge
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
       // Find the root of the sets for u and v
        while (parent[u]) {
            u = parent[u];
        }
        while (parent[v]) {
            v = parent[v];
        }
       // If u and v are in different sets, include this edge
        if (u != v) {
            cout << "Edge " << ne << ": (" << a << "->" << b << ") cost = " << min << endl;
            ne++;
            mincost += min;
            parent[v] = u;
        }
     // Mark this edge as used
        cost[a][b] = cost[b][a] = 999;
    }
     cout << "Minimum cost = " << mincost << endl;
    return 0;
}
/*1*/
#include<iostream>
using namespace std;
int main(){
    int ne=1,n,parent[10],cost[10][10],a,b,u,v,i,j,mincost=0;
    cout<<"enter number of vertices:\n";
    cin>>n;
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    cin>>cost[i][j];
    if(cost[i][j]==0)
    cost[i][j]=999;
    }
    parent[i]=0;
    }
    while(ne<n){
        int min=999;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
           
        }
         while(parent[u])
            u=parent[u];
            while(parent[v])
            v=parent[v];
            if(u!=v){
                cout<<"edge:"<<ne++<<" :( "<<a<<","<<b<<" ) cost= "<<min<<endl;
                parent[v]=u; 
                mincost+=min;
            }
            cost[a][b]=cost[b][a]=999;

    }
    cout<<"minimum cost = "<<mincost<<endl;
    return 0;

}
//*/
