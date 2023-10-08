//kruskals algo
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
#define PARENT 0
#define RANK 1

class disjoint {
    vector<vector<int>> dset;
    int n;

public:
    disjoint(int n) {
        this->n = n;
        dset.resize(n);
        for (int i = 0; i < n; i++) {
            dset[i].resize(2);
            dset[i][PARENT] = -1;
            dset[i][RANK] = 0;
        }
    }

    int find(int i) {
        if (dset[i][PARENT] == -1) {
            return i;
        }
        return dset[i][PARENT] = find(dset[i][PARENT]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (dset[u][RANK] > dset[v][RANK]) {
            dset[v][PARENT] = u;
        } else if (dset[u][RANK] < dset[v][RANK]) {
            dset[u][PARENT] = v;
        } else {
            dset[v][PARENT] = u;
            dset[u][RANK]++;
        }
    }
    

    int kruskals(vector<vector<int>>& v1){
    sort(v1.begin(),v1.end(),comparetor);
        int min_mst=0;
    for(const auto& it:v1){
    
     int u=find(it[0]);
     int v=find(it[1]);
     int weight=it[2];
     
     if(u!=v){
        unite(u,v);
      min_mst += weight;
     }

    }
    return min_mst;
    }

    static bool comparetor(vector<int> &a,vector<int> &b){
        return a[2]<b[2];
    }
};




int main(){
int n;
n=6;
vector<vector<int>>edge_list={{0,1,1},{1,3,1},{2,4,1},{0,2,2},{2,3,2},{3,4,2},{1,2,3},{1,4,3},{4,5,3},{3,5,4}}; 

     disjoint ds(n);

    int mst_weight = ds.kruskals(edge_list);

    cout << "Minimum Spanning Tree Weight: " << mst_weight << endl;

 
    return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vii;
//typedef vector<int> vi;

int n, m, p[100];

int find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = find(p[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        p[x] = y;
    }
}

int kruskal(vector<vii> &adjList) {
    int mst_cost = 0;
    vector<pair<int, pii>> edges;

    for (int i = 0; i < n; i++) {
        for (auto &e : adjList[i]) {
            int w = e.first;
            int to = e.second;
            edges.push_back(make_pair(w, make_pair(i, to)));
        }
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (find(u) != find(v)) {
            unite(u, v);
            mst_cost += w;
        }
    }

    return mst_cost;
}

int main() {
    cin >> n >> m;
    vector<vii> adjList(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(w, v));
        adjList[v].push_back(make_pair(w, u));
    }

    int mst_cost = kruskal(adjList);
    cout << mst_cost << endl;

    return 0;
}
*/