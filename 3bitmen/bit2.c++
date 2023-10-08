
#include<iostream>
using namespace std;

//get bit
int get_bit(int n ,int pos){
// shift i=1 to the pos  (if pos =2)  i<<pos = 100
int i=1<<pos;   // pos =2  i= 100 if we cout <<i = 4;
return ((n&i)!=0);  // n&i will give a number if the no = 0 then there is 0 bit if the no is non zero 2,3,7 ... so there is 1                           
  
}


// set_bit set the pos 1
int set_bit(int n,int pos){
    return (n|(1<<pos)); 
}

// claer bit
int clear_bit(int n, int pos){
int comp=~(1<<pos);     // ~(00100) = 11011
return (n&comp);

}

int main(){
    int n ,pos;
    cin>>n>>pos;
    cout<<clear_bit(n,pos);

return 0;
}

