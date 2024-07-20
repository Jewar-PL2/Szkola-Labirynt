#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <unordered_map>

template <typename T>
class BaseManager {
public:
  T& preload(const std::string& key, const std::string& path) {
    T resource;
    resource.loadFromFile(path);
    resources[key] = resource;
    return resources[key];
  }

  T& get(const std::string& key) {
    return resources[key];
  }
  
private:
  std::unordered_map<std::string, T> resources {};
};