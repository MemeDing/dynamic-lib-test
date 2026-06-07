#include "Module2.hpp"

void Module2::sort(std::vector<int> &vec)
{
    std::cout << "Module 2 sorting begin." << std::endl;
    bubbleSort(vec);
    std::cout << "Module 2 sorting end." << std::endl;
}

void Module2::bubbleSort(std::vector<int> &vec)
{
    bool swapped;

    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        swapped = false;

        for (std::size_t j = 0; j < vec.size() - i - 1; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}