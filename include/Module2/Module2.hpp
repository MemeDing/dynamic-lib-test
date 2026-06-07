#pragma once

#include "IModule/IModule.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Module2 : public IModule
{
public:
    Module2() = default;

    void sort(std::vector<int> &vec) override;

    void bubbleSort(std::vector<int> &vec);
};

extern "C"
{
    IModule *createModule()
    {
        return new Module2();
    }

    void deleteModule(IModule *modulePtr)
    {
        delete modulePtr;
    }
}