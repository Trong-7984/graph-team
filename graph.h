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

#endif // GRAPH_H
