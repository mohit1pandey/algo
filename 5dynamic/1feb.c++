#include<iostream>
using namespace std;

int feb(int n){

int f1=0;
int f2=1;
int f=f1+f2;

if(n<=1){
 return n;
}
else{
    for(int i=2;i<=n;i++){
        f=f1+f2;
        f1=f2;
        f2=f;
    }
}




return f;
}


int main(){

cout<<feb(1000);


    return 0;
}