/*
Sort a given set of elements using the Quicksort method and determine the time
required to sort the elements. Repeat the experiment for different values of n, the
number of elements in the list to be sorted and plot a graph of the time taken versus n.
The elements can be read from a file or can be
generated using the random number generator.
*/
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
void customswap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int low,int high){
    int i=low,j=high,pivot=a[low];
    while(i<j){
        while(a[i]<=pivot && i<=high )
        i++;
        while(a[j]>pivot)
        j--;
        if(i<j){
        customswap(&a[i],&a[j]);
        }
    }
    customswap(&a[low],&a[j]);
    return j;
}
void quick_sort(int a[],int low,int high){
    if(low<high){
        int pi=partition(a,low,high);
        quick_sort(a,low,pi-1);
        quick_sort(a,pi+1,high);
    }
}
int main(){
   
    int n;
    clock_t start,end;
    cout<<"enter the number of elements\n";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    a[i]=rand()%100;
    cout<<"the elements in the array before sorting:";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    start=clock();
    quick_sort(a,0,n-1);
    end=clock();
    cout<<"the elements in the array after sorting :";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<"time taken is: "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}