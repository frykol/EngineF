#include "Game.h"


Game::Game(int width, int height): m_Width(width), m_Height(height), m_DeltaTime(0), m_CurrentFrame(0), m_LastFrame(0){
    m_KeyID = EngineF::EventManager::getInstance().addListener<EngineF::KeyPressEvent>([this](EngineF::KeyPressEvent& e){
        this->handleInput(e);
    });

    EngineF::Window::getInstance().init(1280, 720);
}


void Game::init(){
    
    m_LastFrame = glfwGetTime();

    std::shared_ptr<EngineF::Shader> shader = EngineF::ResourceManager::getInstance().loadShader("../../EngineF/shaders/basic.vertex","../../EngineF/shaders/basic.fragment", "basic");
    EngineF::ResourceManager::getInstance().loadTexture("../../EngineF/textures/brick.jpg", "brick");

    glm::mat4 projection = glm::ortho(0.0f,m_Width,m_Height,0.0f, -1.0f, 1.0f);
    glm::mat4 view = glm::mat4(1.0f);

    m_Renderer = std::make_shared<EngineF::SpriteRenderer>(*shader);
    shader->setUniformMat4("u_View", view);
    shader->setUniformMat4("u_Projection",projection);
    
    shader->unBind();

    update();
}

void Game::update(){
    
    EngineF::Scene scene("basic test");
    m_CurrentScene = &scene;
    m_CurrentScene->testScene();
    


    EngineF::GameObject* testPlayer = new Player(EngineF::ResourceManager::getInstance().getTexture("brick"), glm::vec2(700.0f, 650.0f),
    glm::vec2(300.0f, 50.0f), glm::vec3(1.0f,0.2f,0.1f));


    EngineF::GameObject* test = 
    new EngineF::GameObject(EngineF::ResourceManager::getInstance().getTexture("brick"), glm::vec2(300.0f, 300.0f),
    glm::vec2(200.0f,300.0f), glm::vec3(1.0f, 0.0f,0.0f));

    test->addComponent<EngineF::CollisionComponent>();


    EngineF::GameObject* testTwo =
    new EngineF::GameObject(EngineF::ResourceManager::getInstance().getTexture("brick"), glm::vec2(600.0f, 300.0f),
    glm::vec2(200.0f,300.0f), glm::vec3(0.0f, 0.0f,1.0f));

    //testPlayer->addChild(test);

    test->addChild(testTwo);


    while (EngineF::Window::getInstance().isRunning())
    {   
        calculateDeltaTime();

        EngineF::SpriteRenderer::clear(glm::vec3(0.3f,0.3f,0.3f));

        EngineF::OnDrawEvent onDrawEvent(m_Renderer.get());
        EngineF::EventManager::getInstance().dispatchEvent(onDrawEvent);


        while(m_DeltaTime >= 1.0){

            EngineF::OnUpdateEvent onUpdate;
            EngineF::EventManager::getInstance().dispatchEvent(onUpdate);

            EngineF::OnUserUpdateEvent onUserUpdate;
            EngineF::EventManager::getInstance().dispatchEvent(onUserUpdate);

            m_CurrentScene->destroyNotAliveGameObjects();
            m_DeltaTime--;
        }



        EngineF::Window::getInstance().swapBuffers();
        glfwPollEvents();

        
    }
   
}


void Game::handleInput(EngineF::KeyPressEvent& e){
    if (e.keyCode == GLFW_KEY_E && e.action == GLFW_PRESS){
        EngineF::LOG("yeet", EngineF::LogType::MESSAGE);
        EngineF::GameObject* gameObject = m_CurrentScene->getGameObject(0);
        if(gameObject != nullptr){
            gameObject->setIsAlive(false);
        }
    }
    if (e.keyCode == GLFW_KEY_W && e.action == GLFW_PRESS){
        EngineF::LOG("yeet", EngineF::LogType::MESSAGE);
    }
}

void Game::calculateDeltaTime(){
    m_CurrentFrame = glfwGetTime();
    m_DeltaTime += (m_CurrentFrame - m_LastFrame) / m_MaxFPS;
    m_LastFrame = m_CurrentFrame;
}
