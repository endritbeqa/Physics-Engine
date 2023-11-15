#include <array>
#include <vector>
#include <stddef.h>



template <typename T, size_t N, size_t M, size_t P, size_t Q>
std::array<std::array<T, M>, N> MatrixMultiply(std::array<std::array<T, P>, N> &A, std::array<std::array<T, M>, Q> &B);