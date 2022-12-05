//
// Created by neekostar on 07.10.22.
//
#include "/home/neekostar/CLionProjects/TaDS_LAB3/Menu/MyMenuItem.h"
#include <any>

namespace MyGraph {

    MyMenuItem::MyMenuItem(string _name, MyMenuItem::func_type _func) {
        name = _name;
        func = _func;
    }
    MyMenuItem::MyMenuItem(std::string _name, func_type2 func) {
        name = _name;
        func2 = func;
    }
    void MyMenuItem::run(any &param) {
        return func(param);
    }
    void MyMenuItem::run(vector<std::any>params) {
        return func2(params);
    }
    void MyMenuItem::print() {
        cout << name;
    }
}