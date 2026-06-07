#pragma once

#include <vector>

class IModule
{
public:
    virtual ~IModule() = default;

    virtual void sort(std::vector<int> &) = 0;
};

#define SETUP_MODULE(MODULE_CLASS)            \
    extern "C"                                \
    {                                         \
        IModule *createModule()               \
        {                                     \
            return new MODULE_CLASS();        \
        }                                     \
                                              \
        void deleteModule(IModule *modulePtr) \
        {                                     \
            delete modulePtr;                 \
        }                                     \
    }
