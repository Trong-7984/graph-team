#include <fstream>
#include "graph.h"

void saveGraph(const Graph& g, const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) return;

    auto adj = g.getAdjList();
    int n = adj.size();

    out << n << " " << g.isDirected() << "\n";

    for (int u = 0; u < n; u++) {
        for (auto [v, w] : adj[u]) {
            if (!g.isDirected() && u > v) continue; // tránh ghi trùng
            out << u << " " << v << " " << w << "\n";
        }
    }

    out.close();
}
