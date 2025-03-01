#include "Game.h"

#include "../Logger.h"

#include "../core/Application.h"
#include "../core/ResourceManager.h"


#include "../scene/GameObject.h"
#include "../scene/Scene.h"
#include "Player.h"
#include "Ball.h"



Game::Game(int width, int height){
    EngineF::Application::getInstance().init(width, height);
}


void Game::init(){
    
    
    EngineF::ResourceManager::getInstance().loadTexture("textures/brick.jpg", "brick");
    EngineF::ResourceManager::getInstance().loadTexture("textures/ball.png", "ball");
    EngineF::ResourceManager::getInstance().loadFont("fonts/Arial.ttf", "arial");

    glm::mat4 view = glm::mat4(1.0f);

    m_CurrentScene = EngineF::Application::getInstance().getCurrentScene();

    new Player(glm::vec2(700.0f, 20.0f),glm::vec2(200.0f, 50.0f));

    size_t size = m_CurrentScene->getGameObjectsCount();

    for(size_t i = 0; i<size; i++){
        std::shared_ptr<EngineF::GameObject> gameObject = m_CurrentScene->getGameObject(i).lock();
        gameObject->addComponent<EngineF::CollisionComponent>(EngineF::CollisionComponent::CollisionType::Box, gameObject->getSize());
        gameObject->addComponent<EngineF::SpriteComponent>(EngineF::ResourceManager::getInstance().getTexture("brick"), glm::vec3(1.0f, 0.1f + i/9.0f, 0.1f + i/11.0f));
    }

    EngineF::GameObject* ball = new Ball(glm::vec2(500.0f, 500.0f), glm::vec2(50.0f, 50.0f));
    ball->addComponent<EngineF::SpriteComponent>(EngineF::ResourceManager::getInstance().getTexture("ball"), glm::vec3(1.0f,1.0f,1.0f));

    EngineF::Application::getInstance().run();

}
