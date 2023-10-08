#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class shortestpath {
    int v;
    vector<int> distance;
    vector<bool> relaxed;
    int res;

public:
    shortestpath(int v) {
        this->v = v;
        distance.resize(v, INT32_MAX);
        distance[0] = 0;
        relaxed.resize(v, false);
        res = 0;
    }

    vector<int> mincost(int graph[][4]) {
        for (int count = 0; count < v; count++) {
            int u = -1;
            for (int i = 0; i < v; i++) {
                if (!relaxed[i] && (u == -1 || distance[i] < distance[u])) {
                    u = i;
                }
                
            }
            
            relaxed[u] = true;      
            
            for (int i = 0; i < v; i++) {
                if (graph[u][i] != 0 && !relaxed[i]) {
                    distance[i] = min(distance[i], distance[u]+graph[u][i]);
                }
            }
        }

    return distance;    
    }
    
};

int main() {
    int v = 4;
    int graph[4][4] = {
        {0,5,8,0},
        {5,0,10,15},
        {8,10,0,20},
        {0,15,20,0}
    };

    shortestpath m1(4);
    vector<int>top=m1.mincost(graph);
    
    for(auto it:top){
        cout<< it<<" ";
    }

    return 0;
}
