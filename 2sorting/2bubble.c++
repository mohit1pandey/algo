//bubble sort
#include <iostream>
using namespace std;

int* bubble_sort(int a[],int n){
   int count=0;
   while (count<n-1)
   {
    for (int i=0; i<n-count; i++)
    {
      if(a[i]>a[i+1]){
        int temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
      }
    }
    count++;
   }
   
   return a;


}


int main(){
  
  int a[]={90,80,70,60,50,40,30,20,10};
   int *arr,n;
   n=sizeof(a)/4;

   arr=bubble_sort(a,n);

 for (int i = 0; i < n; i++)
{
    cout<< arr[i];
}

   

return 0;
}
