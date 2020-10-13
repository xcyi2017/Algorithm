#include "SparseGraph.h"
#include "DenseGraph.h"

int main() {
    int n = 20;
    int m = 100;
    SparseGraph g1 = SparseGraph(n, false);
    for (int i = 0; i < m; ++i) {
        int a = std::rand()%n;
        int b = std::rand()%n;
        g1.addEdge(a, b);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << i << " : ";
        SparseGraph::adjIterator adj(g1, i);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
