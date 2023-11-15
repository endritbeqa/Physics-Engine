#include <array>
#include <vector>


class Particle
{

public:
    float m;                /*mass*/
    std::array<float, 3> x; /*position vector*/
    std::array<float, 3> v;
    std::array<float, 3> f; /*forces*/

    Particle(int mass, std::array<float,3> pos,std::array<float,3> velocity, std::array<float,3> forces ){
        m=mass;
        x=pos;
        v=velocity;
        f=forces;
    }
    

    std::array<float, 3> getX()
    {return x;}

    std::array<float, 3> getV()
    {return v;}

    void setX(std::array<float, 3>& newX)
    {x = newX;}

    void setV(std::array<float, 3>& newV)
    {v = newV;}

    std::array<float,6> derivative(){
        
        return {v[0],v[1],v[2],f[0]/m,f[1]/m,f[2]/m,};
    }
   


};

struct ParticleSystem
{
    std::vector<Particle> p;
    int n;
    float t;
};