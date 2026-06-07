#pragma once

#include "IModule/IModule.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Module1 : public IModule
{
public:
    Module1() = default;

    void sort(std::vector<int> &vec) override;

    int partition(std::vector<int> &vec, int low, int high);

    void quickSort(std::vector<int> &vec, int low, int high);
};

extern "C"
{
    IModule *createModule()
    {
        return new Module1();
    }

    void deleteModule(IModule *modulePtr)
    {
        delete modulePtr;
    }
}