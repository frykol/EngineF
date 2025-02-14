#include "Game.h"


Game::Game(int width, int height): m_DeltaTime(0), m_CurrentFrame(0), m_LastFrame(0){

    EngineF::Window::getInstance().init(1280, 720);
    EngineF::Input::getInstance().init();
}


void Game::init(){
    
    m_LastFrame = glfwGetTime();

    

    std::shared_ptr<EngineF::Shader> shader = EngineF::ResourceManager::getInstance().loadShader("../../EngineF/shaders/basic.vertex","../../EngineF/shaders/basic.fragment", "basic");
    EngineF::ResourceManager::getInstance().loadTexture("../../EngineF/textures/brick.jpg", "brick");


    int width = EngineF::Window::getInstance().getWindowWidth(); 
    int height = EngineF::Window::getInstance().getWindowHeight(); 
    
    glm::mat4 view = glm::mat4(1.0f);

    m_Renderer = std::make_shared<EngineF::SpriteRenderer>(*shader);
    shader->setUniformMat4("u_View", view);
    shader->setUniformMat4("u_Projection",EngineF::Window::getInstance().getProjection());
    
    shader->unBind();


    EngineF::Scene scene("basic test");
    m_CurrentScene = &scene;
    m_CurrentScene->testScene();

    new Player(EngineF::ResourceManager::getInstance().getTexture("brick"), glm::vec2(700.0f, 650.0f),
    glm::vec2(200.0f, 50.0f), glm::vec3(1.0f,0.2f,0.1f));


    EngineF::GameObject* test = 
    new EngineF::GameObject(EngineF::ResourceManager::getInstance().getTexture("brick"), glm::vec2(300.0f, 300.0f),
    glm::vec2(200.0f,300.0f), glm::vec3(1.0f, 0.0f,0.0f), "abcTest");

    test->addComponent<EngineF::CollisionComponent>();

    EngineF::GameObject* testTwo =
    new EngineF::GameObject(EngineF::ResourceManager::getInstance().getTexture("brick"), glm::vec2(600.0f, 300.0f),
    glm::vec2(200.0f,300.0f), glm::vec3(0.0f, 0.0f,1.0f));

    testTwo->addComponent<EngineF::CollisionComponent>();


    test->addChild(testTwo);

    EngineF::OnUserInitEvent onUserInitEvent;
    EngineF::EventManager::getInstance().dispatchEvent(onUserInitEvent);

    update();
}

void Game::update(){

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


        handleInput();
        EngineF::Window::getInstance().swapBuffers();
        glfwPollEvents();

        
    }
}


void Game::handleInput(){

    if (EngineF::Input::getInstance().isKeyPressedOnce(GLFW_KEY_E)){
        EngineF::LOG("yeet", EngineF::LogType::MESSAGE);
        EngineF::GameObject* gameObject = m_CurrentScene->getGameObject(0);
        if(gameObject != nullptr){
            gameObject->setIsAlive(false);
        }
    }
    // if (EngineF::Input::getInstance().isKeyPressed(GLFW_KEY_W)){
    //     std::string size = std::to_string(m_CurrentScene->getGameObjects().size());
    //     EngineF::LOG(size, EngineF::LogType::MESSAGE);
    // }
}

void Game::calculateDeltaTime(){
    m_CurrentFrame = glfwGetTime();
    m_DeltaTime += (m_CurrentFrame - m_LastFrame) / m_MaxFPS;
    m_LastFrame = m_CurrentFrame;
}
