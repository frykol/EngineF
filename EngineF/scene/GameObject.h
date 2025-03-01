#pragma once

#include <memory>
#include <vector>

#include "../core/SpriteRenderer.h"
#include "../core/Texture.h"
#include "../core/Input.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../events/EventManager.h"
#include "../events/GameObjectEvents.h"
#include "../events/GameObjectCreatedEvent.h"
#include "../events/DrawEvent.h"

#include "../components/Component.h"
#include "../components/CollisionComponent.h"
#include "../components/SpriteComponent.h"
#include "../components/TextComponent.h"

#include "Scene.h"

namespace EngineF{
    class GameObject{
        protected:
            glm::vec2 m_Position;
            glm::vec2 m_Size;
            glm::vec3 m_Color;

            std::string m_Name;

            bool m_IsActive;
            bool m_IsAlive;
            bool m_IsVisible;
        private:
            

            GameObject* m_Parent;
            std::vector<GameObject*> m_Childrens;

            std::vector<std::unique_ptr<Component>> m_Components;

            ListenerID m_OnUserInitID;
            ListenerID m_OnUserUpdateID;
            ListenerID m_OnUpdateID;

            void init();
            //void update(OnUpdateEvent& e);
            
        public:
            GameObject(glm::vec2 position, glm::vec2 size, std::string name = "Test");
            virtual ~GameObject();


            void setPosition(glm::vec2 position);
            glm::vec2 getPosition();

            
            void update();
            virtual void userInit(OnUserInitEvent& e) {};
            virtual void userUpdate() {};

            virtual void onCollision(CollisionComponent* collision) {};

            void setParent(GameObject* parent);
            void addChild(GameObject* child);
            void removeAllChildren();

            template<typename ComponentType, typename... Args>
            void addComponent(Args... args){
                m_Components.emplace_back(std::make_unique<ComponentType>(this, args...));
            }


            void setPositionX(float x);
            float getPositionX();

            void setPositionY(float y);
            float getPositionY();

            void setSize(glm::vec2 size);
            glm::vec2 getSize();

            bool getIsAlive();
            void setIsAlive(bool isAlive);

            bool getIsVisible();
            void setIsVisible(bool isVisible);

            bool getIsActive();
            void setIsActive(bool isActive);

            std::string& getName();
    };
}