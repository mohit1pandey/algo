#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>> floyed(vector<vector<int>> A ,int n){
  
  for(int k=0;k<n;k++){
  for(int i=0;i<n; i++){

   for (int j = 0; j <n; j++)
   {
      A[i][j]= min (A[i][j],A[i][k]+A[k][j]);   // here k is woking as the previous value of the graph and the new one we are creating
   }
  }
  }

return A;
}

int main(){
   vector<vector<int>>graph;
    
    int n=4;

   graph={{0,3,1000,7},
          {8,0,2,1000},
          {5,1000,0,1},
          {2,1000,1000,0} };

vector<vector<int>> v1=floyed(graph,n);

for (int i = 0; i <4; i++)
{
    for(int j=0;j<n;j++){
     cout<< v1[i][j];
    }
    cout<<endl;
}


    return 0;
}