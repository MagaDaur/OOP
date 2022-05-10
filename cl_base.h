#ifndef __CHE
#define __CHE

#include <vector>
#include <string>

class cl_base
{
public:
    cl_base(cl_base* parent, std::string name);
    ~cl_base();

    void SetName(std::string);
    std::string GetName();
    
    void ChangeParent(cl_base*);
    cl_base* GetParent();
    cl_base* GetChildByName(std::string);

    void PrintChildren();
    void AddChild(cl_base*);
    
    //ДОРАБОТКА
    void SetState(int);
    int GetState();
    void PrintChildrenReadiness();
    int GetLevel();

private:
    std::string name;
    cl_base* parent;
    std::vector<cl_base*> children;
    
    // ДОРАБОТКА
    int state;
};

#endif
