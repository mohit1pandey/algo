#include<iostream>
using namespace std;

//power of 2
 int power2(int n){
  if (n==0)return 0;
  else {
    return !(n&n-1);  // if the n is power of 2 then the n&n-1 = 0 and ! will flip it to 1;
                      // else if the n&n-1 is non zero ! will flip it to 0;
  }

 }


int main(){
int n;
cin>>n;
cout<<power2(n);
    return 0;
}