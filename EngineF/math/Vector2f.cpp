
#include "Vector2f.h"

namespace EngineF{
    Vector2f::Vector2f(float a, float b): first(a), second(b){}


    Vector2f operator+(Vector2f& a, Vector2f& b){
        return Vector2f(a.first+b.first, a.second+b.second);
    }
}