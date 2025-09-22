//
// Created by Hsinpa on 2025/9/18.
//

#include "SimpleTriangleApp.h"
#include <algorithm>
#include <print>
#include <stdexcept>

void SimpleTriangleApp::initialize(GLFWwindow *window) {
    this->window = window;
    this->createInstance();
}

void SimpleTriangleApp::createInstance() {

    VkApplicationInfo appInfo{VK_STRUCTURE_TYPE_APPLICATION_INFO};
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
    appInfo.apiVersion = VK_API_VERSION_1_1; // 1.0 also OK

    VkInstanceCreateInfo ci{VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
    ci.pApplicationInfo = &appInfo;
}

void SimpleTriangleApp::mainLoop() {

}

void SimpleTriangleApp::cleanup() {
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
}