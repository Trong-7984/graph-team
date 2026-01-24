#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

class Graph {
private:
    int n;                                      // số đỉnh
    bool directed;                             // đồ thị có hướng hay không
    vector<vector<pair<int,int>>> adj;         // danh sách kề

public:
    // Khởi tạo đồ thị
    Graph(int n, bool directed = false) {
        this->n = n;
        this->directed = directed;
        adj.resize(n);
    }

    // Thêm cạnh (u -> v) với trọng số w
    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        if (!directed) {
            adj[v].push_back({u, w});
        }
    }

    // Lấy danh sách kề
    vector<vector<pair<int,int>>> getAdjList() {
        return adj;
    }
    // ===== IN DANH SACH KE =====
    void printAdjList();

    // ===== IN DANH SACH CANH =====
    void printEdgeList();

    // ===== IN MA TRAN KE =====
    void printAdjMatrix();
};
Chuyển ma trận kề - Danh sách kề
  void matrixToAdjList() {
       adjList.assign(n, {});
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               if (adjMatrix[i][j] != 0) {
                   adjList[i].push_back({j, adjMatrix[i][j]});
               }
           }
       }
   }
Chuyển danh sách kề - Ma trận kề
  void adjListToMatrix() {
       adjMatrix.assign(n, vector<int>(n, 0));
       for (int u = 0; u < n; u++) {
           for (auto [v, w] : adjList[u]) {
               adjMatrix[u][v] = w;
           }
       }
   }
Chuyển danh sách kề - Danh sách cạnh
  void adjListToEdgeList() {
       edgeList.clear();
       for (int u = 0; u < n; u++) {
           for (auto [v, w] : adjList[u]) {
               if (directed || u < v) {
                   edgeList.push_back({u, v, w});
               }
           }
       }
   }
Chuyển danh sách cạnh - Danh sách kề
  void edgeListToAdjList() {
       adjList.assign(n, {});
       for (auto e : edgeList) {
           adjList[e.u].push_back({e.v, e.w});
           if (!directed) {
               adjList[e.v].push_back({e.u, e.w});
           }
       }
   }
void printPath(int v, vector<int>& parent) {
    if (v == -1) return;
    printPath(parent[v], parent);
    cout << v << " ";
}

void Dijkstra(Graph g, int startNode) {
    int n = g.getAdjList().size();
    vector<vector<pair<int, int>>> adj = g.getAdjList();

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    dist[startNode] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, minDist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!visited[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    cout << "\nDijkstra (co duong di):\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Khong co duong tu " << startNode << " den " << i << endl;
        }
        else {
            cout << "Tu " << startNode << " den " << i
                << " (do dai = " << dist[i] << "): ";
            printPath(i, parent);
            cout << endl;
        }
    }
}
#endif // GRAPH_H
