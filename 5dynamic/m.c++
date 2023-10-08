
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cost;
vector<vector<int>> kval;

// Function to print the 2D matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

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

    for (int d = 0; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            int j = d + i;

            int min_cost = INT16_MAX;

            for (int k = i; k <= j; k++) {
                int q = ((k > i) ? cost[i][k - 1] : 0) + ((k < j) ? cost[k + 1][j] : 0) + weight(i, j, freq);

                if (q < min_cost) {
                    min_cost = q;
                    kval[i][j] = k; // root of the tree for which the cost is min
                }

                cost[i][j] = min_cost;
            }
        }
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
