#include "ArrayUtils.cpp"
#include "VectorUtils.cpp"
#include "MatrixUtils.cpp"
#include "iostream"

int main()
{

   int num = 4;
   int *address = &num;
   int num2 = *address;
   int **address2 = &address;
   int *num3 = *address2;
   int ***address3 = &address2;

   std::array<int, 5> a = {1, 2, 3, 4, 5};
   std::array<int, 5> b = {2, 3, 4, 5, 6};
   std::array<int, 5> c = {1, 2, 3, 4, 5};
   std::array<float, 5> d = {1, 2, 3, 4, 5};
   std::array<float, 5> e = {1, 2, 3, 4, 5};
   std::array<float, 5> f = {1, 2, 3, 4, 5};

   std::array<std::array<int, 3>, 4> A = {{{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {3, 4, 5}}};
   std::array<std::array<int, 3>, 4> B = {{{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {3, 4, 5}}};

   std::vector<float> av = {1, 2, 3, 4, 5};
   std::vector<float> bv = {1, 2, 3, 4, 5};
   std::vector<float> cv = {1, 2, 3, 4, 5};
   std::vector<float> dv = {1, 2, 3, 4, 5};

   NormalizeVector(av);
   ScaleVector(bv, 0.5);
   auto ev = AddVectors(cv, dv);

   setArrayToZero(a);
   auto aa = AddArrays(b, c);
   NormalizeArray(d);
   ScaleArray(e, 2);

   auto AB = MatrixMultiply(B, A);

   std::cout << "Breakpoint";
   return 0;
}