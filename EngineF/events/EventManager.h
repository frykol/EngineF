#pragma once

#include "Event.h"

#include <functional>
#include <unordered_map>
#include <typeindex>

namespace EngineF{
    using ListenerID = size_t;
    class EventManager{
        public:
            

            template<typename EventType>
            ListenerID addListener(std::function<void(EventType&)> listener){
                auto key = std::type_index(typeid(EventType));

                ListenerID id = nextListenerID++;
                listeners[key].push_back({id, [listener](Event& event){
                    listener(static_cast<EventType&>(event));
                }});
                return id;
            }

            template<typename EventType>
            void removeListener(ListenerID id){
                auto key = std::type_index(typeid(EventType));

                auto& listenersList = listeners[key];
                listenersList.erase(
                    std::remove_if(listenersList.begin(), listenersList.end(),
                        [id](const Listener& listener) {
                            return listener.id == id;
                        }),
                    listenersList.end());
            }

            void dispatchEvent(Event& event){
                auto key = std::type_index(typeid(event));

                if(listeners.find(key) == listeners.end())
                    return;
                for(auto& listener : listeners[key]){
                    listener.callback(event);
                }
            }

            static EventManager& getInstance(){
                static EventManager instance;
                return instance;
            }
        private:
            EventManager() = default;

            


            struct Listener{
                ListenerID id;
                std::function<void(Event&)> callback;
            };
        
            std::unordered_map<std::type_index, std::vector<Listener>> listeners;
            ListenerID nextListenerID = 0;
    };

    
}