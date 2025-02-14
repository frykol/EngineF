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


#include "../components/Component.h"
#include "Scene.h"

namespace EngineF{
    class Component;
    class GameObject{
        protected:
            std::shared_ptr<Texture> m_Texture;
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

            ListenerID m_OnDrawID;
            ListenerID m_OnUserInitID;
            ListenerID m_OnUserUpdateID;
            ListenerID m_OnUpdateID;

            void init();
            void draw(OnDrawEvent& e);
            void update(OnUpdateEvent& e);
        public:
            GameObject(std::shared_ptr<Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color, std::string name = "Test");
            virtual ~GameObject();

            void setTexture(std::shared_ptr<Texture> texture);
            std::shared_ptr<Texture> getTexture();

            void setPosition(glm::vec2 position);
            glm::vec2 getPosition();

            

            virtual void userInit(OnUserInitEvent& e) {};
            virtual void userUpdate(OnUserUpdateEvent& e) {};

            virtual void onCollision(GameObject* collision) {};

            void setParent(GameObject* parent);
            void addChild(GameObject* child);
            void removeAllChildren();

            template<typename ComponentType>
            void addComponent(){
                std::unique_ptr<ComponentType> g = std::make_unique<ComponentType>(this);
                m_Components.push_back(std::move(g));
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

            std::string& getName();
    };
}