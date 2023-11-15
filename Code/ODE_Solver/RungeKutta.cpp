#include "../utils/ArrayUtils.cpp"



/*
Runge-Kutta Method for ODE

T- type used for representing state values of object
N- number of object state parameters(e.g position, velocity, mass etc.)
M- number of object state parameters that change(e.g position, velocity)

Input 
tn-total time 
h- time step
yn- state of object at step n
fty- pointer to derivative function of object

Output
std::array<T,M> array of object state parameters that changed 
*/


template <typename T, size_t N>
std::array<T,N> RungeKutta(float tn,float h, std::array<T,N> &yn, std::array<T,N> (*fty)( std::array<T, N>) ){

   
   std::array<T,N> yn_1= yn;

   std::array<T,N> k1 = fty(tn, yn);
   std::array<T,N> k2=  fty(tn+h/2, yn+ h*k1/2);
   std::array<T,N> k3=  fty(tn+h/2, yn+ h*k2/2);
   std::array<T,N> k4=  fty(tn+h, yn+ h*k3);

   std::array<T,N> sum = AddArrays(k1,ScaleArray(k2,2));
   sum=AddArrays(sum,ScaleArray(k3,2));
   sum=AddArrays(sum,k4);
   sum=ScaleArray(sum, h/6);

   yn_1=AddArrays(yn_1, sum);
 
   return yn_1;

};


/*
Euler Method for ODE

T- type used for representing state values of object
N- number of object state parameters(e.g position, velocity, mass etc.)
M- number of object state parameters that change(e.g position, velocity)

Input 
tn-total time 
h- time step
yn- state of object at step n
fty- pointer to derivative function of object

Output
std::array<T,M> array of object state parameters that changed 
*/



template <typename T, size_t N, size_t M>
std::array<T,M> Euler(float tn,float h, std::array<T,N> yn, std::array<T,N> (*fty)(float, std::array<T, N>) ){

   std::array<T,N> k1 = fty(tn, yn);
   std::array<T,N> yn_1= AddArrays(yn, ScaleArray(k1,h));

   return yn_1;
};

