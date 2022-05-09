#include "cl_application.h"
#include <iostream>

int main()
{
    std::string root_name;
    std::cin >> root_name;
    
    cl_application app(nullptr, root_name);
    app.bild_tree_objects(); // создание дерева
    return app.exec_app();
}
