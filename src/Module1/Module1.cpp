#include "Module1.hpp"

void Module1::sort(std::vector<int> &vec)
{
    std::cout << "Module 1 sorting begin." << std::endl;
    quickSort(vec, 0, vec.size() - 1);
    std::cout << "Module 1 sorting end." << std::endl;
}

int Module1::partition(std::vector<int> &vec, int low, int high)
{
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (vec[j] <= pivot)
        {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

void Module1::quickSort(std::vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(vec, low, high);

        quickSort(vec, low, pivotIndex - 1);
        quickSort(vec, pivotIndex + 1, high);
    }
}