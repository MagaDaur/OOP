#ifndef __CHE1
#define __CHE1

#include "cl_base.h"
#include <string>

class cl_application : public cl_base
{
public:
    cl_application(cl_base* parent, std::string name = "Object_root") : cl_base(parent, name) {};
    
    void bild_tree_objects();
    int exec_app();
};

#endif
