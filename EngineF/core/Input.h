#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <unordered_map>
#include "Window.h"

#include "../events/InputEvent.h"

namespace EngineF{
    class Input{
        private:
            std::unordered_map<int, bool> m_KeyStates;
            std::unordered_map<int, bool> m_KeyPressedThisFrame;

            ListenerID m_KeyPressedID;

            Input() = default;
            static Input* m_Input;

        public:
            Input(const Input&) = delete;
            Input& operator=(const Input&) = delete;

            static Input& getInstance(){
                return *m_Input;
            }

            void init();
            void setKey(KeyPressEvent& e);
            bool isKeyPressed(int key);
            bool isKeyPressedOnce(int key);
    };
}