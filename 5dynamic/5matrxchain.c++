#include<iostream>
#include<vector>
#include <climits> 
using namespace std;

int cost[5][5];     // though vakues will start form 1 index
int kval[5][5];        // to store the k value for min cost at i,j

void min_cost_mutiplication (int n ,int p[]){

  for(int d=1;d<n-1;d++){                // first calculate for d=1 then d=2 .........
   
    for(int i=1; i<n-d;i++){             // at any state i value is < n-d
     
      int j=i+d;
      
      int min=INT16_MAX ;

      for(int k=i ;k<=j-1;k++){             // to get the k value for the formula

       int q = cost[i][k]+cost[k+i][j]+(p[i-1])*(p[k])*(p[j]);

        if(q<min){
            min=q;
            kval[i][j]=k;
        }    
      }
      cost[i][j]=min;                 // put the min csot for i,j multiplication

    }

  }
cout<<"min cost: "<<cost[1][n-1]<<endl;
}

void print_parathiisis(int n){
for(int j=n-1;j>0;j--){
    cout<<'A'<<kval[1][j]<<" ";     // ((A1) A2 A3) A4
}

}



int main(){
    int n=5;
    int p[]={5,4,6,2,7};
   
   min_cost_mutiplication(n,p);
 
   print_parathiisis(n);
   
    return 0;
}