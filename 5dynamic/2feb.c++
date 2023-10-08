#include<iostream>
using namespace std;

int f[51];


int feb(int n){

if(n<=1)return n;

if(f[n]!=-1){
   return f[n];
}

f[n]=feb(n-1)+feb(n-2);
return f[n];


}
int main(){


int n;cin>>n;
for(int i=0;i<=n;i++){
f[i]=-1;

}
cout<<feb(n);


    return 0;
}





/*
#include<iostream>
using namespace std;

int feb(int n){


if(n<=1){
    return n;
}else{

    return(feb(n-1)+feb(n-2));
}
}


int main(){
int n;cin>>n;
cout<<feb(n);


    return 0;
}
*/