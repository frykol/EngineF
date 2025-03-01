#pragma once


namespace EngineF{

    class GameObject;

    class Component{
        protected:
            GameObject* m_Owner;
        public:
            Component(GameObject* gameObject);
            virtual ~Component() = 0;

            virtual void init() {};
            virtual void update() {};
    };
}