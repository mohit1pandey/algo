#include<iostream>
using namespace std;


//update bit
int update_bit(int n,int pos ,bool bit){
if (bit==1){
return (n|(1<<pos));
}
else{
int comp=~(1<<pos);
return (n&comp);
}
}

int main(){
int n,pos;
bool bit;
cin>>n>>pos>>bit;
cout<<update_bit(n,pos,bit);

    return 0;
}
/*it will use both of the function clear bit and update bit*/