// insertion sort
#include<iostream>
using namespace std;


int* insert_sort(int arr[] ,int n){
for (int i =1;i<=n; i++){
int j=i-1;
int curr=arr[i];
while (arr[j]>curr && j>=0)
{
   arr[j+1]=arr[j];
   j--;
}
arr[j+1] =curr;
}


return arr;
}
int main(){

int arr[]={ 10,9,8,7,5,6,1,2,3};
int s= sizeof(arr)/sizeof(int);
int *arr1=insert_sort(arr,s-1);
for(int i=0;i<s;i++){
cout<<arr[i]<<" ";
}
    return 0;
}