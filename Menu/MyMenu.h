

#include "/home/neekostar/CLionProjects/TaDS_LAB3/Menu/MyMenuItem.h"
#include "../../TaDS_LAB3/Models/Errors.h"
#include <any>
#include <iostream>
#include <vector>

namespace MyGraph {
using namespace std;
    class MyMenu {
    public:
        using func_type = void (*)(any &param);
        using func_type2 = void(*)(std::vector<any> params);
        MyMenu();

        MyMenu(string _name, MyMenuItem *items, size_t count);

        void print();

        void runCommand(any &param);
        void runCommand(std::vector<any> params);

    private:
        int m_select{-1};
        size_t m_count{};
        string m_title{};
        MyMenuItem *m_items{};
    };

}
 //MYMENU_CMENU_H
