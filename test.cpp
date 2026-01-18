#include <iostream>
#include "Graph.h" // File định nghĩa lớp Graph của bạn

// Khai báo prototype các hàm nếu chúng nằm ở file .cpp khác
void BFS(Graph& g, int startNode);
void DFS(Graph& g, int startNode);
bool isBipartite(Graph& g);

using namespace std;
// --- CHƯƠNG TRÌNH TEST NHANH ---
int main(){
// Tạo đồ thị có 5 đỉnh (0 đến 4)
    Graph  g(5);

    // Thêm các cạnh (u, v)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    // Gọi các hàm để kiểm tra
    BFS(g, 0);
    DFS(g, 0);

    if (isBipartite(g)) {
        cout << "Do thi la do thi phan doi." << endl;
    }
    else {
        cout << "Do thi KHONG phai la do thi phan doi." << endl;
    }
    cout << endl;
    g.printAdjList();

    cout << endl;
    g.printEdgeList();

    cout << endl;
    g.printAdjMatrix();
    return 0;
