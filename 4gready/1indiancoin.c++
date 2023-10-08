// indian coin problem
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int no_notes(vector<int>& v,int ammount){
int count=0;
// now make the whole array reverse
sort(v.begin(),v.end(),greater<int>());
// treverse in the whole array(revrese sorted array)
// as we get the value equal or smaller than the ammount do operation
 for(int i=0;i<v.size();i++){
 // keep the record that how much times the ammount has been devided
 count += ammount/v[i];

// reduce the ammount (count * a[i]) from ammount
 ammount = ammount -(ammount/v[i])*v[i];   // ammount -= (ammount/v[i])*v[i]

 }
 return count;
}


int main(){
    int paisa;
    cin>>paisa;
vector<int>v1={2,1,5,10,20,50,100,500,200,2000};
int n=v1.size();
cout<<no_notes(v1,paisa);
    return 0;
}
