#pragma once
namespace EngineF{
    class Vector2f{
        public:
            float first;
            float second;

            Vector2f(float a, float b);
          
              
    };

    Vector2f operator+(Vector2f& a, Vector2f& b); 
}