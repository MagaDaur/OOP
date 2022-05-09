#include "cl_application.h"
#include <iostream>

void cl_application::bild_tree_objects() // создание дерева объектов ДОРАБОТКА
{
    while(true)
    {
        std::string parent_name, child_name;
        int child_class_num = 0;
        
        std::cin >> parent_name;
        if(parent_name == "endtree")
            break;
            
        std::cin >> child_name >> child_class_num;
        
        cl_base* found_parent = GetChildByName(parent_name);
        if(found_parent)
            cl_base* new_child = new cl_base(found_parent, child_name, child_class_num); // создание нового дочернего объекта
    }
    
    while(true)
    {
        std::string child_name;
        int state_num;
        
        std::cin >> child_name;
        
        if(child_name == "stop")
            break;
        
        std::cin >> state_num;
        
        cl_base* child = GetChildByName(child_name);
        if(child)
            child->SetState(state_num);
    }
}

int cl_application::exec_app() // запуск приложения ДОРАБОТКА
{
    std::cout << "Object tree" << std::endl;
    PrintChildren();
    std::cout << std::endl << "The tree of objects and their readiness";
    PrintChildrenReadiness();
    return 0;
}
