#include<iostream>
#include<vector>
#define inf INT16_MAX
using namespace std;

vector<int> shortest_path(int n, int m, vector<vector<int>> &edgelist){

vector<int> dest(n,inf);

int src=0;
dest[src]=0;

//for n-1
for(int i=0;i<n;i++){

    for(int j=0;j<m;j++){

    int u=edgelist[j][0];
    int v=edgelist[j][1];
    int edgecost=edgelist[j][2];
        
          
     if(dest[u] !=inf && (dest[u]+edgecost) <dest[v]){
        dest[v]= dest[u]+edgecost;
     }

    }

}


// checking for -ive cylcle
bool negativecycel=false;

   for(int j=0;j<m;j++){

    int u=edgelist[j][0];
    int v=edgelist[j][1];
    int edgecost=edgelist[j][2];
        
          
     if(dest[u] !=inf && (dest[u]+edgecost) <dest[v]){
       negativecycel=true;

     }

    }
  

  if(negativecycel){
    cout<< "graph contains -ive cycle";
  }else{
     cout <<" result is ok no -ive cycle";
  }
return dest;
}

int main(){

  int n=4;
  int m=4;

  vector<vector<int>> edgelist={{2,1,-5},{3,2,3},{0,3,5},{0,1,4}};

  vector<int> v1=shortest_path(n,m,edgelist);
  

  for(auto a:v1){
   cout<<a <<" ";
  }
    return 0;
}