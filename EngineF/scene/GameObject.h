#pragma once

#include <memory>
#include <vector>

#include "../core/SpriteRenderer.h"
#include "../core/Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../events/EventManager.h"
#include "../events/GameObjectCreatedEvent.h"

#include "../events/GameObjectEvents.h"

#include "../components/Component.h"

namespace EngineF{
    class Component;

    class GameObject{
        protected:
            std::shared_ptr<Texture> m_Texture;
            glm::vec2 m_Position;
            glm::vec2 m_Size;
            glm::vec3 m_Color;


            bool m_IsActive;
            bool m_IsAlive;
            bool m_IsVisible;
        private:
            

            GameObject* m_Parent;
            std::vector<GameObject*> m_Childrens;

            std::vector<std::unique_ptr<Component>> m_Components;

            ListenerID m_OnDrawID;
            ListenerID m_OnUserUpdateID;
            ListenerID m_OnUpdateID;

            void init();
            void draw(OnDrawEvent& e);
            void update(OnUpdateEvent& e);
        public:
            GameObject(std::shared_ptr<Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color);
            ~GameObject();

            void setTexture(std::shared_ptr<Texture> texture);
            std::shared_ptr<Texture> getTexture();

            void setPosition(glm::vec2 position);
            glm::vec2 getPosition();

            

            virtual void userInit() {};
            virtual void userUpdate(OnUserUpdateEvent& e) {};

            void setParent(GameObject* parent);

            void addChild(GameObject* child);

            void removeAllChildren();

            template<typename ComponentType>
            void addComponent(){
                m_Components.push_back(std::unique_ptr<ComponentType>(new ComponentType(this)));
            }


            void setPositionX(float x);
            float getPositionX();

            void setPositionY(float y);
            float getPositionY();

            void setSize(glm::vec2 size);
            glm::vec2 getSize();

            void setColor(glm::vec3 color);
            glm::vec3 getColor();

            bool getIsAlive();
            void setIsAlive(bool isAlive);

            bool getIsVisible();
            void setIsVisible(bool isVisible);

            bool getIsActive();
            void setIsActive(bool isActive);
    };
}