#pragma once

#include <unordered_map>

#include "../events/EventManager.h"
#include "../events/InputEvent.h"

namespace EngineF{
    class Window;
    class Input{
        friend Window;
        private:
            Window* m_Window;

            std::unordered_map<int, bool> m_KeyStates;
            std::unordered_map<int, bool> m_KeyPressedThisFrame;

            ListenerID m_KeyPressedID;

        protected:
            Input(Window* window): m_Window(window) {};
        public:

            void init();
            void setKey(KeyPressEvent& e);
            bool isKeyPressed(int key);
            bool isKeyPressedOnce(int key);
    };
}