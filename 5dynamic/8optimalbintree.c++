// C[i,j] = min{c[i, k-1] + c[k,j]} + w(i,j)
/*
0   1   2   3   4 representaive 
|   |   |   |   |
0   10  20  30  40 acutal val 
0   4   2   6   3  ferquency
*/
# include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>>cost;
vector<vector<int>>kval;

// w(i,j)
int weight(int i,int j,vector<int> & freq){
    int w=0;
   for (int i = 0; i <=j; i++)
   {
       w = w + freq[i];
   }
   return w;
}


int optimal_BST(int n,vector<int> & freq){
  // n=5
for (int d= 0;d<n;d++){
    for(int i= 0;i<n-d;i++){
        int j= d+i;
        
        int min=INT16_MAX;

       for(int k=i+1;k<=j;k++){
       
       int q=(cost[i][k-1]+cost[k][j])+weight(i,j,freq);
       
       if(q<min){
        min=q;
        kval[i][j]=k;  // root of the tree for which the cost is min
       }

       cost[i][j]=min;

       }
    }
}
return 0;

}






int main(){
    
    vector<int>elem={0,1,2,3,4};
    vector<int>frequency={0,4,2,6,3};
 

    return 0;

}