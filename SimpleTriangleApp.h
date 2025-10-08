//
// Created by Hsinpa on 2025/9/18.
//

#ifndef VULKAN_TOOLS_SIMPLETRIANGLEAPP_H
#define VULKAN_TOOLS_SIMPLETRIANGLEAPP_H
#define GLFW_INCLUDE_VULKAN
#include <optional>
#include <vector>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value();
    }

};

class SimpleTriangleApp {
public:
    void initialize(GLFWwindow* window);
    void cleanup();
    void mainLoop();

private:
    GLFWwindow* window = nullptr;
    VkInstance instance;
    VkSurfaceKHR surface;

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;

    void createInstance();
    void createSurface();
    void pickPhysicalDevice();
    bool checkValidationLayerSupport();
    bool isDeviceSuitable(VkPhysicalDevice device);
    void createLogicalDevice();
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };


#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

};


#endif //VULKAN_TOOLS_SIMPLETRIANGLEAPP_H