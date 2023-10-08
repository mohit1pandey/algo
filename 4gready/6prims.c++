// prims algo 
#include<iostream>
#include<vector>
using namespace std;

class mst{

vector<int>mstx;   // in this list i will keep the record of the chosen vertices 
vector<int>cost;   // gives the cost of the snallest edge associated with the index (vertex)
int v;             // no of vertex
int mincost;
public:

mst(int v){
    this->v=v;
    mstx.resize(v,false);
    cost.resize(v,INT32_MAX);
    cost[0]=0;                // because we starting treversal from 0
     mincost=0;
}

int cost_mst(vector<vector<int>> &graph){
for (int count=0; count<v;count++){

  int u= -1;  // start from outside
  for(int i=0;i<v;i++){                     // will provide the vertex connected(to u) with minimum cost 
    
   // !mstx[i]  it will prevent tose values are coloured  // u== -1 will allow u to get the value of non visited vertex                                 
  if(!mstx[i]&& (u==-1 || cost[i]<cost[u]) )     
   u=i;      // u will always start form -1 and will get the vlaue of non visited vertex

  }
 mincost +=cost[u];
 mstx[u]=true;

// now for every vertex we need to get the all possible costs

for(int i=0;i<v;i++){

if(graph[u][i]!=0 && !mstx[i]){
   
   cost[i]=min(cost[i],graph[u][i]);
}

}


}
return mincost;

};



};

int main(){
int v=4;
vector<vector<int>>graph{ {0,5,8,0},
                      {5,0,10,15},
                      {8,10,0,20},
                      {0,15,20,0}};

    mst m1(4);
    cout << m1.cost_mst(graph);

    return 0;
}