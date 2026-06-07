#pragma once

#include <vector>

class IModule
{
public:
    virtual ~IModule() = default;

    virtual void sort(std::vector<int> &) = 0;
};