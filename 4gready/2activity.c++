// n activities are given and strting and end times are also provided find the max no of activities
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(vector<int> &a,vector<int>& b){
//we need a ka second element b ke second element se kam
return (a[1]<b[1]);

}


int max_acivity(vector<vector<int>>& v ,int n){
// fill the vector

int start,finish;
for (int i = 0; i <n; i++)
{
    cin>>start>>finish;
  v.push_back({start,finish});
}
// to sort the array in terms of their ending times

sort(v.begin(),v.end(),compare);  // by defualt sorting fiest element but we want for second element

int take =1;                       // take will take care of the activities
int end=v[0][1] ;                   // ending time of frist process
for(int i=1;i<n;i++){
 if(v[i][0]>=end){
     take++;
    end =v[i][1];
 }

}
return take;
}

int main(){

int n;
cin>>n;
// activity vector consist of ststing and end time
vector<vector<int>>v1;

cout<<max_acivity(v1,n);

    return 0;
}