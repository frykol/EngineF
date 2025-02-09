#include "Game.h"

Game::Game(int width, int height): m_Width(width), m_Height(height){

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
    EngineF::GLLOG([]{glewInit();});
}

void Game::init(){
    initOpenGl();

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
    scene.testScene();

    std::vector<std::shared_ptr<EngineF::GameObject>>& gameObjects = scene.getGameObjects();

    std::shared_ptr<EngineF::GameObject> testPlayer =  gameObjects[0];

    float dir = 1;

    while (!glfwWindowShouldClose(m_Window))
    {   
        

        m_Renderer->clear(glm::vec3(0.3f,0.3f,0.3f));
        for(int i = 0; i<gameObjects.size(); i++){
            m_Renderer->drawSprite(*gameObjects[i]->getTexture(), gameObjects[i]->getPosition(), gameObjects[i]->getSize(), gameObjects[i]->getColor());
        }
        
        testPlayer->setPositionX(testPlayer->getPositionX() + 100.0f * dir * EngineF::SpriteRenderer::getDeltaTime());


        if(testPlayer->getPositionX() <= 0.0f || testPlayer->getPositionX() + testPlayer->getSize().x >= m_Width){
            dir *= -1;
        }

        m_Renderer->swapBuffers(m_Window);
    
        glfwPollEvents();

        
        
    }
}