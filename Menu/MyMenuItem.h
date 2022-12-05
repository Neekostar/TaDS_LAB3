//
// Created by neekostar on 07.10.22.
//
#pragma once

#include <iostream>
#include <string>
#include <any>
#include "../../TaDS_LAB3/Models/Errors.h"
#include <vector>

using namespace std;
namespace MyGraph {

    class MyMenuItem {
    public:
        using func_type = void (*)(any &param);
        using func_type2 = void (*)(vector<any> params);
        MyMenuItem(string _name, func_type _func);
        MyMenuItem(string _name, func_type2 _func);
        void run(any &param);
        void run(vector<any> params);
        void print();


    private:
        std::string name{};
        func_type func = nullptr;
        func_type2 func2 = nullptr;
        vector<any> params{};
    };

}//MYMENU_CPP_MYMENUITEM_H
