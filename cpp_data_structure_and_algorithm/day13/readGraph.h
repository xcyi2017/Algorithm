//
// Created by xcy on 2020/10/11.
//

#ifndef DAY13_READGRAPH_H
#define DAY13_READGRAPH_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cassert>

template<typename Graph>
class ReadGraph {
public:
    ReadGraph(Graph &graph, const std::string &filename);
};

template<typename Graph>
ReadGraph<Graph>::ReadGraph(Graph &graph, const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    int V, E;
    assert(file.is_open());
    assert(getline(file, line));

    std::stringstream ss(line);
    ss >> V >> E;
    assert(V == graph.V());

    for (int i = 0; i < E; i++) {
        assert(getline(file, line));
        std::stringstream ss(line);
        int a, b;
        ss >> a >> b;
        assert(a >= 0 && a < V);
        assert(b >= 0 && b < V);
        graph.addEdge(a, b);
    }
}

#endif //DAY13_READGRAPH_H
