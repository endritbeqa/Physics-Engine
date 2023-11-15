#include "../Objects/Object.cpp"
#include "../utils/ArrayUtils.cpp"
#include <vector>

class Force
{

public:
    std::array<float, 3> direction;
    float magnitude;

    Force() {}

    Force(std::array<float, 3> d, float m)
    {
        direction = d;
        magnitude = m;
    }

    virtual void apply(Object &obj){};
    virtual void apply(Object &obj1, Object &obj2){};
    virtual void apply(std::vector<Object> &objs){};
};

class GravityForce : public Force
{

    GravityForce(std::array<float, 3> direction, float magnitude) : Force(direction, magnitude) {}

    void apply(Object &o)
    {
        o.f = AddArrays(direction, o.f);
    }
};

class ViscousDrag : public Force
{
public:
    ViscousDrag(float magnitude) : Force(std::array<float, 3>{0.0, 0.0, 0.0}, magnitude)
    {
    }

    void apply(Object &o)
    {
        std::array<float, 3> velocity = o.v;
        ScaleArray(velocity, -magnitude);
        o.f = AddArrays(o.f, velocity);
    }
};

class DampedSpring : public Force
{

public:
    float Ks;
    float Kd;
    float r;

    DampedSpring(float SpringConstant, float DampingConstant, float RestLength)
    {
        Ks = SpringConstant;
        Kd = DampingConstant;
        r = RestLength;
    }

    void apply(Object &obj1, Object &obj2)
    {
        std::array<float, 3> diffPos = SubstractArrays(obj1.x, obj2.x);
        std::array<float, 3> diffVelocity = SubstractArrays(obj1.v, obj2.v);
        float dotProd = DotProductArrays(diffPos, diffVelocity);
        float normPos = NormArray(diffPos);

        float a = -(Ks * (normPos - r) + Kd * (dotProd / normPos)) * (1 / normPos);

        std::array<float, 3> f = diffPos;
        ScaleArray(f, a);
        obj1.f = AddArrays(obj1.f, f);

        ScaleArray(f, -1);
        obj2.f = AddArrays(obj2.f, f);
    }
};
