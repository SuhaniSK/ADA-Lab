/*
Implement a parallelized Merge Sort algorithm to sort a given set of elements and
determine the time required to sort the elements. Repeat the experiment for different
values of n, the number of elements in the list to be sorted and plot a graph of the time
taken versus n. The elements can be read from a file or can be generated using the
random number generator
*/
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
void merge(int a[],int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    int b[500];
    while(i<=mid&&j<=high){
        if(a[i]<=a[j])
        b[k++]=a[i++];
        else
        b[k++]=a[j++];
    }
    while(i<=mid)
     b[k++]=a[i++];
     while(j<=high)
     b[k++]=a[j++];
     for(int i=low;i<=high;i++)
     a[i]=b[i];
}
void merge_sort(int a[],int low,int high){
    if (low<high){
        int mid=(high-low)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
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
    merge_sort(a,0,n-1);
    end=clock();
    cout<<"the elements in the array after sorting :";
     for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<"time taken is: "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}