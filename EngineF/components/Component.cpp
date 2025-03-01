#include "Component.h"
namespace EngineF{
    Component::Component(GameObject* gameObject): m_Owner(gameObject) {}
    Component::~Component() {
        
    }
}