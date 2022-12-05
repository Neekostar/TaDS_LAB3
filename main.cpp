//
// Created by neekostar on 07.10.22.
//
#include <iostream>
#include "Models/Graph.h"
#include "Menu/MyMenu.h"
#include "Menu/MyMenuItem.h"
#include "Models/Errors.h"
#include <cstdlib>
#include <fstream>
#include <any>
#include <cstring>
#include <vector>

#define LOAD_GRAPH auto *gr = any_cast<Graph*>(params[0]);
#define LOAD_OUTPUT_FILE auto out = any_cast<string>(params[1]);
#define LOAD_DATA_FILE auto fn = any_cast<string>(params[2]);

using namespace MyGraph;
using namespace std;

const int pointsOfMenu = 14;

std::string load_data_file = "/home/neekostar/CLionProjects/TaDS_LAB3/Input.txt";
std::string write_data_file = "/home/neekostar/CLionProjects/TaDS_LAB3/Output.txt";
std::string log_data_file = "/home/neekostar/CLionProjects/TaDS_LAB3/Errors.txt";

void GraphCreateGraph(vector<any>params) {
    LOAD_GRAPH;
    gr->deleteGraph();
    cout << "Введите количество вершин:\n";
    int k{};
    string k_input;
    cin >> k_input;
    k = stoi(k_input);
    for (int i = 0; i < k; ++i) {
        gr->addVertex();
    }
    cout << "Вершины добавлены\n";

    cout << "Введите количество ребер\n";
    cin >> k_input;
    k = stoi(k_input);
    int x, y;
    string x_input, y_input;
    for (int i = 0; i < k; ++i) {
        cout << "Введите ребро парой чисел\n";
        cin >> x_input;
        cin >> y_input;
        x = stoi(x_input);
        y = stoi(y_input);
        gr->addEdge(x, y);
    }
    cout << "Ребра добавлены\n";
}

void GraphPrintMatrix(vector<any>params) {
    LOAD_GRAPH;
    system("clear");
    bool empty = gr->checkForEmpty();
    if (empty) {
        cout << endl << "Граф пуст, заполните его\n\n";
    } else {
        cout << "Граф в виде матрицы смежности:\n";
        gr->printAdjanecyMatrix();
        cout << endl;
    }
}

void GraphPrintList(vector<any>params) {
    LOAD_GRAPH;
    system("clear");
    bool empty = gr->checkForEmpty();
    if (empty) {
        cout << endl << "Граф пуст, заполните его\n\n";
    } else {
        cout << "Граф в виде спсика смежности:\n";
        gr->printAdjanecyList();
        cout << endl;
    }
}

void GraphExit(vector<any>params) {
    LOAD_GRAPH;
    LOAD_OUTPUT_FILE;
    exit(0);
}

void GraphAddEdge(vector<any>params) {
    LOAD_GRAPH;
    int x, y;
    string x_input, y_input;
    cout << "Граф:" << endl;
    gr->printAdjanecyMatrix();
    cout << "Введите ребро:\n";
    cin >> x_input;
    cin >> y_input;
    x = stoi(x_input);
    y = stoi(y_input);
    gr->addEdge(x, y);
}

void GraphAddVertex(vector<any>params) {
    LOAD_GRAPH;
    cout << "Граф:" << endl;
    gr->printAdjanecyMatrix();
    gr->addVertex();
    cout << "Вершина успешно добавлена" << endl;
    gr->printAdjanecyMatrix();
}

void GraphRemoveVertex(vector<any>params) {
    LOAD_GRAPH;
    cout << "Граф:" << endl;
    gr->printAdjanecyMatrix();
    int k;
    string k_input;
    cout << "Введите вершину для удаления:" << endl;
    cin >> k_input;
    bool empty = gr->checkForEmpty();
    if (empty) {
        cout << "Граф пуст" << endl;
    } else {
        k = stoi(k_input);
        gr->removeVertex(k);
        cout << "Вершина удалена" << endl;
    }
}

void GraphRemoveEdge(vector<any>params) {
    LOAD_GRAPH;
    cout << "Граф:" << endl;
    gr->printAdjanecyMatrix();
    int x, y;
    string x_input, y_input;
    cout << "Введите ребро для удаления:" << endl;
    cin >> x_input;
    cin >> y_input;
    x = stoi(x_input);
    y = stoi(y_input);
    gr->removeEdge(x, y);
    cout << "Ребро удалено" << endl;
}

void GraphCountOfVertexes(vector<any>params) {
    LOAD_GRAPH;
    cout << "Количество вершин в графе: " << gr->getCountOfVertexes() << endl;
}

void GraphBFS(vector<any>params) {
    LOAD_GRAPH;
    cout << "Обход графа в ширину:" << endl;
    gr->BFS();
}

void GraphDFS(vector<any>params) {
    LOAD_GRAPH;
    cout << "Обход графа в глубину:" << endl;
    gr->DFS();
}

void GraphLongestDistance(vector<any>params){
    LOAD_GRAPH;
    gr->modDFS();
}


void GraphOutputToFile(vector<any>params) {
    LOAD_GRAPH;
    cout << "Запись графа в файл" << endl;
    gr->outputGraphToFile(write_data_file);
}

void GraphReadFromFile(vector<any>params) {
    LOAD_GRAPH;
    LOAD_DATA_FILE;
    cout << "Чтение графа из файла" << endl;
    gr->readGraphFromFile(load_data_file);
}

string Errors::file_name = "Errors.txt";


int main(int argc, char *argv[]) {
    std::string load_data_file = "Input.txt";
    std::string write_data_file = "Output.txt";
    std::string log_data_file = "Errors.txt";

    if (argc >= 3) {
        load_data_file = argv[1];
        write_data_file = argv[2];
        log_data_file = argv[3];
    }
    Errors::setFileName(log_data_file);

    Graph *graph = new Graph;

    MyMenuItem items[pointsOfMenu]{
            MyMenuItem{"Создать граф", GraphCreateGraph},
            MyMenuItem{"Матрица смежности графа", GraphPrintMatrix},
            MyMenuItem{"Список смежности графа", GraphPrintList},
            MyMenuItem{"Добавить ребро", GraphAddEdge},
            MyMenuItem{"Добавить вершину", GraphAddVertex},
            MyMenuItem{"Удалить ребро", GraphRemoveEdge},
            MyMenuItem{"Удалить вершину", GraphRemoveVertex},
            MyMenuItem{"Количество вершин", GraphCountOfVertexes},
            MyMenuItem{"Обход в ширину", GraphBFS},
            MyMenuItem{"Обход в глубину", GraphDFS},
            MyMenuItem{"Запись данных в файл", GraphOutputToFile},
            MyMenuItem{"Чтение данных из файла", GraphReadFromFile},
            MyMenuItem{"Самый длинный путь", GraphLongestDistance},
            MyMenuItem{"Выход из программы", GraphExit}
    };
    MyMenu menu("Меню графа", items, pointsOfMenu);
    vector<any>param = {graph, write_data_file, load_data_file};
    GraphReadFromFile(param);
    while (true) {
        try {
            menu.runCommand(param);
        }
        catch (const Errors &ex) {
            cout << "Error: " << ex.getError() << endl;
            menu.runCommand(param);
        }
    }
    return 0;
}