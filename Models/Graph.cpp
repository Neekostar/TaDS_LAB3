//
// Created by neekostar on 16.11.22.
//

#include "Graph.h"
#include <iomanip>
#include <vector>

namespace MyGraph {

    void Graph::printAdjanecyMatrix() {
        for (int i = 0; i < n; ++i) {
            std::cout << "\n";
            for (int j = 0; j < n; ++j) {
                std::cout << " " << adjList[i][j];
            }
        }
        std::cout << std::endl << std::endl;
    }

    void Graph::printAdjanecyList() {
        std::cout << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << i << " => ";
            for (int j = 0; j < n; j++) {
                if (adjList[i][j] == 1) {
                    std::cout << j << ",";
                }
            }
            std::cout << std::endl;
        }
    }

    void Graph::addEdge(int x, int y) {
        if ((x >= n) || (y >= n)) {
            std::cout << "Не существует такой вершины, к которой можно добавить ребро!\n\n";
            return;
        }
        if (x == y) {
            std::cout << "\nНельзя создавать петли. Вы выбрали ту же вершину\n\n";
            return;
        } else {
            adjList[y][x] = 1;
            adjList[x][y] = 1;
            std::cout << "\nРебро графа добавлено!\n\n";
        }
    }

    void Graph::addVertex() {
        for (int i = 0; i < n; ++i) {
            adjList[i].push_back(0);
        }
        n++;
        std::vector<int> temp;
        for (int i = 0; i < n; ++i) {
            temp.push_back(0);

        }
        adjList.push_back(temp);
    }

    void Graph::removeEdge(int x, int y) {
        if ((x >= n) || (y >= n)) {
            std::cout << "Не существует такого ребра!\n\n";
            return;
        }
        if (x == y) {
            std::cout << "\nТа же самая вершина!\n\n";
            return;
        } else {
            adjList[y][x] = 0;
            adjList[x][y] = 0;
            std::cout << "\nРебро графа удалено!\n\n";
        }
    }

    void Graph::removeVertex(int x) {
        if (x > n) {
            std::cout << "\nТакой вершины не существует, введите другую!\n\n";
            return;
        } else {
            int i;
            while (x < n - 1) {
                for (i = 0; i < n; ++i) {
                    adjList[i][x] = adjList[i][x + 1];
                }
                for (i = 0; i < n; ++i) {
                    adjList[x][i] = adjList[x + 1][i];
                }
                x++;
            }
            n--;
        }
    }

    void Graph::BFS() {
        std::vector<int> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back(0);
        }
        std::queue<int> Queue;
        Queue.push(0);
        while (!Queue.empty()) {
            int node = Queue.front();
            Queue.pop();
            nodes[node] = 2;
            for (int j = 0; j < n; j++) {
                if (adjList[node][j] == 1 && nodes[j] == 0) {
                    Queue.push(j);
                    nodes[j] = 1;
                }
            }
            std::cout << node + 1 << std::endl;
        }
        std::cout << std::endl;
    }

    void Graph::DFS() {
        std::vector<int> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back(0);
        }
        std::stack<int> Stack;
        Stack.push(0);
        while (!Stack.empty()) {
            int node = Stack.top();
            Stack.pop();
            if (nodes[node] == 2) continue;
            nodes[node] = 2;
            for (int j = n - 1; j >= 0; j--) {
                if (adjList[node][j] == 1 && nodes[j] != 2) {
                    Stack.push(j);
                    nodes[j] = 1;
                }
            }
            std::cout << node + 1 << std::endl;
        }
        std::cout << std::endl;
    }

    bool Graph::checkForEmpty() {
        bool check = false;
        if (adjList.empty()) {
            check = true;
        }
        return check;
    }

    void Graph::deleteGraph() {
        n = 0;
        adjList.clear();
        adjList.shrink_to_fit();
    }

    int Graph::getCountOfVertexes() {
        return n;
    }

    void Graph::modDFS() {
        int *dp = new int(getCountOfVertexes());
        int prev = 0;
        int cntr = 0;
        bool fl = false;
        int tmp_point = 0;
        for (int i = 0;i<getCountOfVertexes(); i++) {
            dp[i] = 0;
        }
        std::vector<int> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back(0);
        }
        std::stack<int> Stack;
        Stack.push(0);
        cntr++;
        while (!Stack.empty()) {
            int node = Stack.top();
            Stack.pop();
            cntr--;
            if (node!=0) {
                dp[node] = std::max(dp[node], dp[prev]+1);
            }
            if (nodes[node] == 2) continue;
            nodes[node] = 2;
            for (int j = n - 1; j >= 0; j--) {
                if (adjList[node][j] == 1 && nodes[j] != 2) {
                    Stack.push(j);
                    cntr++;
                    nodes[j] = 1;
                }
            }
            if (fl) {
                prev = tmp_point;
                fl = false;
            }
            else {
                prev = node;
            }
            if (cntr>1) {
                tmp_point = node;
                fl = true;
            }
            //std::cout << node + 1 << std::endl;
        }
        std::cout << std::endl;
        int rezult = dp[0];
        for (int i = 0; i<getCountOfVertexes();i++) {
            std::cout <<"Максимальный путь из вершины "<< i << " составляет " << dp[i] << "\n";
            if (dp[i]>rezult) {
                rezult = dp[i];
            }
        }
        std::cout <<"Самый длинный путь: "<< rezult;

    }


    void Graph::readGraphFromFile(std::string fileName) {
        int x, y;
        std::ifstream in;
        in.open(fileName);

        if (!in) {
            std::cout << "Файл не открывается.\n";
            return;
        } else {
            in >> n;

            std::vector<int> temp;
            for (int i = 0; i < n; ++i) {
                temp.push_back(0);
            }
            for (int i = 0; i < n; ++i) {
                adjList.push_back(temp);
            }

            while (!in.eof()) {
                for (y = 0; y < n; y++) {
                    for (x = 0; x < n; x++) {
                        in >> adjList[x][y];
                    }
                }
            }
            in.close();
            std::cout << "Данные успешно считаны!" << std::endl;
        }
    }


    void Graph::outputGraphToFile(std::string fileName) {
        std::ofstream out;
        out.open(fileName);

        if (!out) {
            std::cout << "Файл не открывается.\n";
            return;
        } else {
            out << n << std::endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    out << adjList[i][j] << " ";
                }
                out << std::endl;
            }
            std::cout << "\nДанные записаны в файл" << std::endl << std::endl;
        }
        out.close();
    }
}
