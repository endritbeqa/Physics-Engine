

class Object
{

public:
    float m;                /*mass*/
    std::array<float, 3> x; /*position vector*/
    std::array<float, 3> v;
    std::array<float, 3> f; /*forces*/

    Object(int mass, std::array<float, 3> pos, std::array<float, 3> velocity, std::array<float, 3> forces)
    {
        m = mass;
        x = pos;
        v = velocity;
        f = forces;
    }
};