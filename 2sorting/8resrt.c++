//reverse sorting 1D vector

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// with greater<int>()
// it returns true if the first arg is greater then the second one

void srt(vector<int> &v, int n){
sort(v.begin(),v.end(),greater<int>());

for (int i=0;i<n;i++){
cout<<v[i]<<" ";
}
}

int main(){
vector<int>v1={15,17,11,13,19,16,14,13};

int n=v1.size();

// print vector
for (int i=0;i<n;i++){
cout<<v1[i]<<" ";
}
cout<< endl;
// sort
srt(v1,n);

    return 0;
}