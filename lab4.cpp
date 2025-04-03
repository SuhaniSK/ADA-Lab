/*
Find a subset of a given set S = {sl, s2,. ,sn} of n positive integers whose sum is equal
to a given positive integer d. For example, if S= {1, 2, 5, 6, 8} and d = 9
there aretwo solutions {1,2,6}and{1,8}.A suitable message is to be displayed if the given
probleminstance doesn’t have a solution.
*/
#include<iostream>
using namespace std;
int set[10],s[10],flag=0,d,n;
int c=0;
void display(int c){
cout<<"{";
for(int i=0;i<c;i++)
cout<<set[i]<<",";
cout<<"}";
cout<<endl;
}
void subset(int sum,int i){
    if(sum==d){
        display(c);
        flag=1;
        return;
    }
    if(sum>d||i>=n)
    return;
    else{
        set[c]=s[i];
        c++;
        subset(sum+s[i],i+1);
        c--;
        subset(sum,i+1);
    }
}
int main(){
cout<<"enter the number of elements\n";
cin>>n;
cout<<"enter the elements:";
for(int i=0;i<n;i++)
cin>>s[i];
cout<<"enter the sum:\n";
cin>>d;
cout<<"the program solution is :\n";
subset(0,0);
if(flag==0)
cout<<"no solution";
return 0;
}