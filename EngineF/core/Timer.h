#pragma once

namespace EngineF{
    class Timer{
        private:
            float m_CurrentFrame;
            float m_DeltaTime;
            float m_LastFrame;
            float m_MaxFPS;
        public: 
            Timer();

            void update();
            
            void setMaxFps(float maxFps);
            float getDeltaTime();

            void resetDeltaTime();
    };
}