// no of 1 in a binary representation of no
// eg if 21 so 10101 no of ones is 3
#include<iostream>
using namespace std;
int no_of1(int n){
    // we will use the power of 2 here
int count =0;
while (n)  // till gets 0
{ n= n&n-1; 
 
 count ++;
 // as soon as n will reach to in the trems of power2 the loop will break 

}
return count;

}

int main(){ 
    int n;

    cin>>n;

cout<<no_of1(n);
return 0;
}