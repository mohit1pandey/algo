// liner serach
#include<iostream>
#define max_val 15
using namespace std;



bool liner_search(int arr[],int n,int search){
 for(int i=0;i<n;i++){
    if(arr[i]==search)return true;
 }
return false;
}


int main(){

int val;
cin>>val;

int arr[]={10,20,50,15,30,44,22,11,1,7,6};

cout<<liner_search(arr,sizeof(arr)/4, val);

return 0;

}