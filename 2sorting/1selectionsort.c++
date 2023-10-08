// selection sort
#include<iostream>
using namespace std;

int* s_sort(int arr[],int n){
   for(int i=0;i<n;i++){
     for(int j=i+1;j<n;j++){
      if(arr[i]>arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
     }
    
   }
   return arr;

}



int main(){

int arr[]={10,40,90,40,60,70,30,20};
int n=sizeof(arr)/4;

int* arrs= s_sort(arr,n);
for (int i = 0; i < n; i++)
{
    cout<< arrs[i];
}


    return 0;
}