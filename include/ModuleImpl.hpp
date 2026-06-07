#pragma once

#include "IModule/IModule.hpp"

#include <iostream>
#include <string>
#include <dlfcn.h>

class ModuleImpl
{
public:
    explicit ModuleImpl(const char *libName);
    ~ModuleImpl();

    ModuleImpl(const ModuleImpl &) = delete;
    ModuleImpl operator=(const ModuleImpl &) = delete;

    ModuleImpl(ModuleImpl &&o) noexcept;

    IModule *operator->();

private:
    template <typename T>
    T loadSymbol(const char *symbolName)
    {
        auto symbol = dlsym(handle, symbolName);
        if (!symbol)
        {
            throw std::runtime_error(dlerror());
        }

        return reinterpret_cast<T>(symbol);
    }

    void *handle{nullptr};
    IModule *module{nullptr};

    using createModule_t = IModule *(*)();
    createModule_t createModule{nullptr};

    using deleteModule_t = void (*)(IModule *);
    deleteModule_t deleteModule{nullptr};
};