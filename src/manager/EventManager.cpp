#include "EventManager.hpp"
#include "../constants/Constants.hpp"
#include <iostream>
#include <mutex>

using namespace Gerenciadores;

EventManager::EventManager(){};

EventManager::~EventManager(){};

EventManager *EventManager::getInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_manager == NULL) {
    _manager = new EventManager();
  }

  return _manager;
};
