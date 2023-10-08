#include<iostream>
// #include<vector>
#include<algorithm>
using namespace std;

int max_profit(int price [], int weight[] ){

int m=4,n=8;

int v [m+1][n+1];     //n=col m= row

for(int i=0;i<=m;i++){
   
   for(int w=0 ;w<=n;w++){
    
    if(i==0||w==0){
        v[i][w]=0;
    }
    else if(weight[i]<=w){
      
      v[i][w]=max(v[i-1][w], v[i-1][w-weight[i]]+price[i]);
         
    }else{

        v[i][w]=v[i-1][w];
    }
   }

}

cout<<v[m][n];

//to find the inclued weight

 int i = m, j = n;

    while (i > 0 && j > 0) {
        if (v[i][j] == v[i - 1][j]) {
            cout << i<< "=0" << endl;
            i--;

        } else {
            cout << i << "=1" << endl;
            j -= weight[i];
            i--;
        }
    }

return 0;
}




int main(){

int price [5]={0,1,2,5,6};
int weight [5]={0,2,3,4,5};

max_profit(price,weight);

    return 0;
}