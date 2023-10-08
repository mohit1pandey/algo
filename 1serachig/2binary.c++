//binary serarch 
#include<iostream>
using namespace std;


bool binary_search(int arr[],int n, int val){
    int s=0;
    int e=n;

while(s<=e){
   int mid =(s+e)/2;
   if(arr[mid]==val)return true;
   
    else if(val<arr[mid]){
        e=mid-1;
    }
    else{
        s=mid+1;
    }
}
return false;


}


int main(){
   int arr[]={10,20,30,40,55,66,77,142,175,200};
   int search;
   int n=sizeof(arr)/4;
   cin>>search;

   cout<<binary_search(arr,n-1,search);
    return 0;
}


// with recursion

//binary serarch 
/*
#include<iostream>
using namespace std;


bool binary_search(int arr[],int s,int e, int val){

int mid=(s+e)/2;
if(s<=e){

   if(arr[mid]==val)return true;

  else if(arr[mid]>val){
    binary_search(arr,s,mid-1,val);
  }
  else{
    binary_search(arr,s+1,e,val);
  }
}
 
   else return false;
}


int main(){
   int arr[]={10,20,30,40,55,66,77,142,175,200};
   int search;
   int n=sizeof(arr)/4;
   cin>>search;

   cout<<binary_search(arr,0,n-1,search);
    return 0;
}
*/