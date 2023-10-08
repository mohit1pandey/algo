//sorting 2D vector
// with respect to first element and with respect to second element

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// i have to costmize the a custom_compare
// by defualt it sorts in treams of  the first element


bool sort_wet2(vector<int>& a,vector<int>& b){  // forward sorts the element wrt second element

return (b[0]<a[0]);
}


bool sort_revrs0(vector<int>& a,vector<int>& b){  // revrese sorts the element wrt first element

return (a[0]>b[0]);
}


bool sort_revrs1(vector<int>& a,vector<int>& b){  // revrese sorts the element wrt second element

return (a[1]>b[1]);
}

void Td_sort(vector<vector<int>> & v,int n){
sort(v.begin(),v.end(),sort_revrs1);

for(int i=0;i<n;i++){
    for(int j=0;j<v[0].size();j++){
        cout<<v[i][j];
    }
}

}


int main(){

vector<vector<int>> v1={{1,9},{5,8},{9,7},{4,6}};
int n =v1.size();
for(int i=0;i<n;i++){
    cout<<'{';
    for(int j=0;j<v1[0].size();j++){
        cout<<v1[i][j];
    }
    cout<<"}"<<" ";
}
cout<< endl;
Td_sort(v1,n);

    return 0;
}