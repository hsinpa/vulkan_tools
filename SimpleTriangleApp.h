//
// Created by Hsinpa on 2025/9/18.
//

#ifndef VULKAN_TOOLS_SIMPLETRIANGLEAPP_H
#define VULKAN_TOOLS_SIMPLETRIANGLEAPP_H
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

class SimpleTriangleApp {
public:
    void initialize(GLFWwindow* window);
    void cleanup();
    void mainLoop();

private:
    GLFWwindow* window = nullptr;
    VkInstance instance;

    void createInstance();
};


#endif //VULKAN_TOOLS_SIMPLETRIANGLEAPP_H