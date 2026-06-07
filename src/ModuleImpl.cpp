#include "ModuleImpl.hpp"

#include <stdexcept>

ModuleImpl::ModuleImpl(const char *libPath)
{
    handle = dlopen(libPath, RTLD_NOW);
    if (!handle)
    {
        throw std::runtime_error("Error loading library '" + std::string(libPath) + "': " + dlerror());
    }

    createModule = loadSymbol<createModule_t>("createModule");
    deleteModule = loadSymbol<deleteModule_t>("deleteModule");

    module = createModule();
    if (module == nullptr)
    {
        throw std::runtime_error("Failed to create module '" + std::string(libPath) + "'");
    }
}

ModuleImpl::~ModuleImpl()
{
    if (handle != nullptr)
    {
        dlclose(handle);
    }
}

ModuleImpl::ModuleImpl(ModuleImpl &&o) noexcept
{
    this->handle = o.handle;
    o.handle = nullptr;
}

IModule *ModuleImpl::operator->()
{
    return module;
}