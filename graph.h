#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Graph {
private:
    int n;
    bool directed;

    // Danh sách kề
    vector<vector<pair<int, int>>> adjList;

    // Ma trận kề
    vector<vector<int>> adjMatrix;

    // Danh sách cạnh
    struct Edge {
        int u, v, w;
    };
    vector<Edge> edgeList;

public:
    // Khởi tạo đồ thị
    Graph(int n, bool directed = false) {
        this->n = n;
        this->directed = directed;

        adjList.assign(n, {});
        adjMatrix.assign(n, vector<int>(n, 0));
    }

    // Thêm cạnh
    void addEdge(int u, int v, int w = 1) {
        adjList[u].push_back({ v, w });
        adjMatrix[u][v] = w;
        edgeList.push_back({ u, v, w });

        if (!directed) {
            adjList[v].push_back({ u, w });
            adjMatrix[v][u] = w;
        }
    }

    // ================= CHUYỂN ĐỔI =================

    // Chuyển ma trận kề -> danh sách kề
    void matrixToAdjList() {
        adjList.assign(n, {});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j] != 0) {
                    adjList[i].push_back({ j, adjMatrix[i][j] });
                }
            }
        }
    }

    // Chuyển danh sách kề -> ma trận kề
    void adjListToMatrix() {
        adjMatrix.assign(n, vector<int>(n, 0));
        for (int u = 0; u < n; u++) {
            for (auto& edge : adjList[u]) {
                adjMatrix[u][edge.first] = edge.second;
            }
        }
    }

    // ================= IN RA =================

    void printAdjList() {
        for (int u = 0; u < n; u++) {
            cout << u << ": ";
            for (auto& edge : adjList[u]) {
                cout << "(" << edge.first << "," << edge.second << ") ";
            }
            cout << endl;
        }
    }

    // *** THÊM – để BFS / DFS / Bipartite chạy
    vector<vector<pair<int, int>>> getAdjList() const {
        return adjList;
    }

    // *** THÊM – lấy số đỉnh
    int size() const {
        return n;
    }
};

#endif
