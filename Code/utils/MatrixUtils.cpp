#include <array>
#include <stddef.h>
#include <stdexcept>


template <typename T, size_t N, size_t M, size_t P, size_t Q>
std::array<std::array<T, M>, N> MatrixMultiply(std::array<std::array<T, P>, N> &A, std::array<std::array<T, M>, Q> &B)
{
    if (Q != P)
    {
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplication");
    }

    std::array<std::array<T, M>, N> product;

    for(int i=0; i<N; i++){
        product[i].fill((T)0);
    }


    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < P; k++)
        {
            for (int j = 0; j < M; j++)
            {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }
return product;
}


