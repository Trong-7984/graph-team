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

#endif // GRAPH_H
