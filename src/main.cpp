#include <iostream>
#include <random>
#include <chrono>

#include "ModuleImpl.hpp"

std::vector<int> generateRandomVector(std::size_t n)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 1000);

    std::vector<int> vec;
    vec.reserve(n);

    for (std::size_t i = 0; i < n; ++i)
    {
        vec.push_back(dist(gen));
    }

    return vec;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "usage: module_test </path/to/module>" << std::endl;
        return 1;
    }

    ModuleImpl module1 = ModuleImpl(argv[1]);
    ModuleImpl module2 = ModuleImpl(argv[2]);

    std::vector<int> testVec1 = generateRandomVector(1000);
    std::vector<int> testVec2{testVec1};

    auto start1 = std::chrono::high_resolution_clock::now();
    module1->sort(testVec1);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    module2->sort(testVec2);
    auto end2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

    if (testVec1 == testVec2)
    {
        std::cout << "Successful sort from both!" << std::endl;
        for (int i : testVec1)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Ouch, something is different" << std::endl;
    }

    if (duration1 < duration2)
    {
        std::cout << "Module 1 was " << (duration2 - duration1).count() << " microseconds faster than Module 2!" << std::endl;
    }
    else
    {
        std::cout << "Module 2 was " << (duration1 - duration2).count() << " microseconds faster than Module 1!" << std::endl;
    }

    return 0;
}