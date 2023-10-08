//multistage graph

/*in this problem we find a shortest path from a given vertex to a end vertex the djsksta can also be used but 
here we have to apply the dynamic programing concept */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cost[8];

int d[8];
int path[4];

void shortest(vector<vector<int>> v1, int n){

for (int i =n-2; i>=0 ; i--)    // i= node no
{
    int min=55555;           // k uuse aage ke node
   
    for(int k=i+1; k<n;k++){      //in caes o i=n-1 k will be 8 in first iteration but 8 the node does not exist
        if(v1[i][k]!=0 && v1[i][k]+cost[k]<min){
            min=v1[i][k]+cost[k];
            d[i]=k;    // for k the cost is min so break the loop and exit
        }
    }
    cost[i]=min;
}

}


int main(){
  path[0]=0;
  path[3]=7;
vector<vector<int>> v1={
     { 0, 1, 2, 5, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 4, 11, 0, 0 },
    { 0, 0, 0, 0, 9, 5, 16, 0 },
    { 0, 0, 0, 0, 0, 0, 2, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 18 },
    { 0, 0, 0, 0, 0, 0, 0, 13 },
    { 0, 0, 0, 0, 0, 0, 0, 2 },
    { 0, 0, 0, 0, 0, 0, 0, 0 }
};
shortest(v1,8);


for(int i=1;i<4;i++){
path[i]=d[path[i-1]];
}
for(int i=0; i<4;i++){
    cout<<path[i];
}



cout<<endl<<"cost_is "<<cost[0];

    return 0;
}