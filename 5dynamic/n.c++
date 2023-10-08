
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cost;
vector<vector<int>> kval;

int weight(int i, int j, const vector<int>& freq) {
    int w = 0;
    for (int k = i; k <= j; k++) {
        w += freq[k];
    }
    return w;
}

void optimal_BST(int n, const vector<int>& freq) {
    cost.resize(n, vector<int>(n, 0));
    kval.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        kval[i][i] = i;
    }

    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            int j = i + d;
            cost[i][j] = 55555;

            for (int k = i; k <= j; k++) {
               if(k>i&&k<j){
                 int c=(cost[i][k-1]+cost[k][j])+weight(i,j,freq);
               
       
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    kval[i][j] = k;
                }
            }
            }
        }
    }
}

// Function to print the 2D matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<int> elem = {0, 1, 2, 3, 4};
    vector<int> frequency = {0, 4, 2, 6, 3};

    int n = elem.size();
    optimal_BST(n, frequency);

    // Print the cost matrix
    cout << "Cost Matrix:" << endl;
    printMatrix(cost);

    return 0;
}
