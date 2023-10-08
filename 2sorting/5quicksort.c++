// quick sort
#include<iostream>
#include<utility>
using namespace std;


int partion(int arr[],int start,int end){      //return partion index
 int pivot= arr[end];
 int pivot_index=start;                       // not by 0 for left sub tree(recursion) first will not be 0;
 for (int i=start;i<end;i++){
     if(arr[i]<=pivot){
        swap(arr[i],arr[pivot_index]);
        pivot_index++;
     }
 }
   swap(arr[pivot_index],arr[end]);

   return pivot_index ;
}


void quick_sort(int arr[], int start, int end){
if(start<end){
int partion_I = partion(arr,start,end);
quick_sort(arr,start,partion_I-1);
quick_sort(arr,partion_I+1,end);
}
}
int main(){

int arr[]={20,19,18,15,16,21,22,27};
int s= sizeof(arr)/sizeof(int);
quick_sort(arr,0,s-1);

for ( int i = 0; i < s; i++)
{
    cout<<arr[i]<<" ";
}
    return 0;
}
