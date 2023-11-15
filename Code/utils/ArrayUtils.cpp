#include <array>
#include <vector>
#include <cmath>
#include <stddef.h>
#include <stdexcept>

template <typename T, size_t N>
void setArrayToZero(std::array<T, N> &x)
{
    x.fill((T)0);
}

template <typename T, size_t N>
std::array<T, N> AddArrays(std::array<T, N> &x, std::array<T, N> &y)
{
    int nx = x.size();
    int ny = y.size();

    if (nx != ny)
    {
        throw std::invalid_argument("Input Arrays are not the same size");
    }

    std::array<T, N> sum;

    sum.fill((T)0);

    for (int i = 0; i < nx; i++)
    {
        sum[i] = x[i] + y[i];
    }
    return sum;
}

template <typename T, size_t N>
std::array<T, N> SubstractArrays(std::array<T, N> &x, std::array<T, N> &y)
{
    int nx = x.size();
    int ny = y.size();

    if (nx != ny)
    {
        throw std::invalid_argument("Input Arrays are not the same size");
    }

    std::array<T, N> sum;

    sum.fill((T)0);

    for (int i = 0; i < nx; i++)
    {
        sum[i] = x[i] - y[i];
    }
    return sum;
}

template <typename T, size_t N>
void NormalizeArray(std::array<T, N> &x)
{
    int nx = x.size();
    float sum;

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

template <typename T, size_t N>
void ScaleArray(std::array<T, N> &x, float scaleFactor)
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

template <typename T, size_t N>
float NormArray(std::array<T, N> &x)
{
    int nx = x.size();
    float sum;

    if (nx == 0)
    {
        throw std::invalid_argument("Input vector is of size 0");
    }

    for (int i = 0; i < nx; i++)
    {
        sum += x[i] * x[i];
    }

    return sqrt(sum);
}

template <typename T, size_t N>
T DotProductArrays(std::array<T, N> &x, std::array<T, N> &y)
{
    int nx = x.size();
    int ny = y.size();

    if (nx != ny)
    {
        throw std::invalid_argument("Input Arrays are not the same size");
    }

    std::array<T, N> sum;

    sum.fill((T)0);

    for (int i = 0; i < nx; i++)
    {
        sum[i] = x[i] * y[i];
    }
    return sum;
}