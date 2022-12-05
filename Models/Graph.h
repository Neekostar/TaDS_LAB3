//
// Created by neekostar on 16.11.22.
//

#ifndef TADS_LAB3_GRAPH_H
#define TADS_LAB3_GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <stack>

namespace MyGraph {
    class Graph {
    private:
        std::vector<std::vector<int>> adjList;
        std::vector<std::vector<int>> adjMatrix;
        int n{};
    public:

        Graph() {};

        void printAdjanecyMatrix();

        void printAdjanecyList();

        void addEdge(int x, int y);

        void addVertex();

        void removeEdge(int x, int y);

        void removeVertex(int x);

        void BFS();

        void DFS();

        bool checkForEmpty();

        void deleteGraph();

        void readGraphFromFile(std::string fileName);

        void outputGraphToFile(std::string fileName);

        int getCountOfVertexes();

        void modDFS();

    };
}

#endif //TADS_LAB3_GRAPH_H
