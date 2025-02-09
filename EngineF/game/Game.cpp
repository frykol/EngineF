#include "Game.h"

Game::Game(int width, int height): m_Width(width), m_Height(height){
    initOpenGl();
    init();
    update();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));    
    game->processInput(key, scancode, action, mods);
}

void Game::initOpenGl(){
    if (!glfwInit())
    exit(-1);

    m_Window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);

    if (!m_Window)
        {
            glfwTerminate();
            exit(-1);
        }

    glfwMakeContextCurrent(m_Window);
    
    glfwSetKeyCallback(m_Window, key_callback);

    EngineF::GLLOG([]{glewInit();});
}

void Game::init(){
    

    std::shared_ptr<EngineF::Shader> shader = EngineF::ResourceManager::getInstance().loadShader("../../EngineF/shaders/basic.vertex","../../EngineF/shaders/basic.fragment", "basic");
    EngineF::ResourceManager::getInstance().loadTexture("../../EngineF/textures/brick.jpg", "brick");

    glm::mat4 projection = glm::ortho(0.0f,m_Width,m_Height,0.0f, -1.0f, 1.0f);
    glm::mat4 view = glm::mat4(1.0f);

    m_Renderer = std::make_shared<EngineF::SpriteRenderer>(*shader);
    shader->setUniformMat4("u_View", view);
    shader->setUniformMat4("u_Projection",projection);
    
    shader->unBind();


}

void Game::update(){
    
    EngineF::Scene scene("basic test");
    m_CurrentScene = &scene;
    m_CurrentScene->testScene();
    

    EngineF::GameObject& testPlayer = m_CurrentScene->getGameObject(0);

    float dir = 1;
    int size = m_CurrentScene->getGameObjects().size();
    EngineF::LOG(size, EngineF::LogType::MESSAGE);

    EngineF::GameObject& test = m_CurrentScene->addGameObject(EngineF::ResourceManager::getInstance().getTexture("brick"), glm::vec2(300.0f, 300.0f),
    glm::vec2(200.0f,300.0f), glm::vec3(1.0f, 0.0f,0.0f));

    testPlayer.addChild(&test);

    while (!glfwWindowShouldClose(m_Window))
    {   
        

        EngineF::SpriteRenderer::clear(glm::vec3(0.3f,0.3f,0.3f));
        for(int i = 0; i< m_CurrentScene->getGameObjects().size(); i++){
           m_CurrentScene->getGameObject(i).Draw(*m_Renderer);
        }
        
        testPlayer.setPositionX(testPlayer.getPositionX() + 100.0f * dir * EngineF::SpriteRenderer::getDeltaTime());


        if(testPlayer.getPositionX() <= 0.0f || testPlayer.getPositionX() + testPlayer.getSize().x >= m_Width){
            dir *= -1;
        }

        EngineF::SpriteRenderer::swapBuffers(m_Window);


        glfwPollEvents();

        
    }
   
}

void Game::processInput(int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_E && action == GLFW_PRESS){
        EngineF::LOG("EZ", EngineF::LogType::MESSAGE);
        m_CurrentScene->removeGameObject(0);
    }
}
