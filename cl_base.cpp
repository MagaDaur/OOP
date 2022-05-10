#include "cl_base.h"
#include <iostream>
    
cl_base::cl_base(cl_base* parent, std::string name) // ДОРАБОТКА
{
    SetName(name);
    this->parent = parent;
    if(parent)
        parent->AddChild(this);
}

cl_base::~cl_base()
{
    for(cl_base* child : children)
    {
        delete child;
        child = nullptr;
    }
}

void cl_base::ChangeParent(cl_base* to)
{
    for(int i = 0; i < parent->children.size(); i++)
    {
        if(parent->children[i] == this)
        {
            parent->children.erase(parent->children.begin() + i);
            parent = to;
            parent->AddChild(this);
            return;
        }
    }
}

void cl_base::PrintChildren() // ДОРАБОТКА
{
    int level = 0;
    cl_base* parent = GetParent();
    while(parent)
    {
        level++;
        parent = parent->GetParent();
    }
    
    std::cout << std::endl;
    for(int i = 0; i < level * 4; i++) std::cout << " ";
    std::cout << GetName();
    
    for(cl_base* child : children)
        child->PrintChildren();
}

void cl_base::PrintChildrenReadiness() // ДОРАБОТКА
{
    int level = 0;
    cl_base* parent = GetParent();
    while(parent)
    {
        level++;
        parent = parent->GetParent();
    }
    
    std::cout << std::endl;
    for(int i = 0; i < level * 4; i++) std::cout << " ";
    std::cout << GetName() << " ";
    if(GetState()) std::cout << "is ready";
    else std::cout << "is not ready";
    
    for(cl_base* child : children)
        child->PrintChildrenReadiness();
}

cl_base* cl_base::GetChildByName(std::string name)
{
    if(GetName() == name)
        return this;
    
    for(cl_base* child : children)
    {
        cl_base* found = child->GetChildByName(name);
        if(found)
            return found;
    }
    return nullptr;
}

void cl_base::AddChild(cl_base* child)
{
    children.push_back(child);
}
    
void cl_base::SetName(std::string name)
{
    this->name = name;
}

std::string cl_base::GetName()
{
    return name;
}

cl_base* cl_base::GetParent()
{
    return parent;
}

//ДОРАБОТКА

int cl_base::GetState()
{
    return state;
}

void cl_base::SetState(int state)
{
    if(state)
    {
        cl_base* parent = GetParent();
        while(parent)
        {
            if(!parent->GetState())
            {
                return;
            }
            parent = parent->GetParent();
        }
    }
    else
    {
        for(cl_base* child : children)
        {
            child->SetState(state);
        }
    }
    
    this->state = state;
}

