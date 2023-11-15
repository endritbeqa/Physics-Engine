#include <array>
#include <vector>
#include <stddef.h>
#include <stdexcept>



template <typename T>
void NormalizeVector(std::vector<T> &x)
{

    int nx = x.size(); 
    float sum = 0;

    if (nx == 0)
    {
        throw std::invalid_argument("Input vector is of size 0");
    }

    for (int i = 0; i < nx; i++)
    {
        sum += x[i];
    }

    if (sum == 0)
    {
        throw std::invalid_argument("Input vector is of magnitude 0");
    }

    for (int i = 0; i < nx; i++)
    {
        x[i] /= sum;
    }
}

template <typename T>
void ScaleVector(std::vector<T> &x, float scaleFactor)
{

    int nx = x.size();

    if (nx == 0)
    {
        throw std::invalid_argument("Input vector is of size 0");
    }

    for (int i = 0; i < nx; i++)
    {
        x[i] *= scaleFactor;
    }
}

template <typename T>
std::vector<T> AddVectors(std::vector<T> &x, std::vector<T> &y)
{
    int nx = x.size();
    int ny = y.size();

    if (nx != ny)
    {
        throw std::invalid_argument("Input vectors are not the same size");
    }

    std::vector<T> sum(nx);

    for (int i = 0; i < nx; i++)
    {   sum[i]=0;
        sum[i] = x[i] + y[i];
    }

    return sum;
}
