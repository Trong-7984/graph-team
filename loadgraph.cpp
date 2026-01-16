#include <fstream>
#include "graph.h"

Graph loadGraph(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        throw runtime_error("Không mở được file");
    }

    int n, directed;
    if (!(in >> n >> directed) || n <= 0) {
        throw runtime_error("Dữ liệu đầu file sai");
    }

    Graph g(n, directed);

    int u, v, w;
    while (in >> u >> v >> w) {
        if (u < 0 || u >= n || v < 0 || v >= n) {
            throw runtime_error("Chỉ số đỉnh không hợp lệ");
        }
        g.addEdge(u, v, w);
    }

    in.close();
    return g;
}
