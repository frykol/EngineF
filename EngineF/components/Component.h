#pragma once

#include "../scene/GameObject.h"

namespace EngineF{

    //class GameObject;

    class Component{
        protected:
            GameObject* m_Owner;
        public:
            Component(GameObject* gameObject): m_Owner(gameObject) {};
            virtual ~Component() {};

            virtual void init() {};
            virtual void update() {};
    };
}