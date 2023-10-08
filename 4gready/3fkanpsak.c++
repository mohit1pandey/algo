#include<iostream>
#include<vector>
#include<algorithm>
#define db double

using namespace std;

// this function will return the value of the ratios 
bool compare(vector<int> & a,vector<int> &b){
db r1=(db)a[1]/(db)a[0];
db r2= (db)b[1]/(db)b[0];
return(r1>r2);
}

// make a funciton return me the price at given weight

db price(vector<vector<int>>& v, int n,int w){
// now sort the vector in trems of the ratios
sort(v.begin(),v.end(),compare);
db profit=0.0;

for(int i=0;i<n;i++){

   if(v[i][0]<=w){
	w-=v[i][0];     // v[i][0] = weight of ith element
	profit +=v[i][1];  // v[i][1] = price of ith element
   } 
   else {               // when the w is lesser than v[i][0] we will add the fractional ammount
    profit += v[i][1]* (db)w/(db)v[i][0];    // multiplying price with weight ka fraction
    break;                                 // no need to decerement the weight and just break loop 
   }


}
return profit;

}



int main(){
int w;
cin>>w;
vector<vector<int>>v={{10,10},{20,15},{15,5},{16,20},{20,18}};  // first is weight and second is price
int n = v.size();
cout<<price(v,n,w);

	return 0;
}

/*// frational kanpsack
// C++ program to solve fractional Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item {
	int profit, weight;

	// Constructor
	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
};

// Comparison function to sort Item
// according to profit/weight ratio
static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
	// Sorting Item on basis of ratio
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;

	// Looping through all items
	for (int i = 0; i < N; i++) {
		
		// If adding Item won't overflow,
		// add it completely
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}

		// If we can't add current Item,
		// add fractional part of it
		else {
			finalvalue
				+= arr[i].profit
				* ((double)W / (double)arr[i].weight);
			break;
		}
	}

	// Returning final value
	return finalvalue;
}

// Driver code
int main()
{
	int W = 60;
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << fractionalKnapsack(W, arr, N);
	return 0;
}
*/