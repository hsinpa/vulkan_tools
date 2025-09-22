#include <iostream>
#include <ostream>
#define GLFW_INCLUDE_VULKAN
#include "SimpleTriangleApp.h"

int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

   // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return EXIT_FAILURE;
    }

    // Check that a Vulkan loader + ICD (MoltenVK) is available
    if (!glfwVulkanSupported()) {
        std::cerr << "Vulkan not available (loader/ICD missing). "
                     "Install the Vulkan SDK or Homebrew vulkan-loader + molten-vk.\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    /* Tell GLFW not to create an OpenGL context */
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    /* Create a windowed mode window without OpenGL context */
    window = glfwCreateWindow(640, 480, "Vulkan Window", NULL, NULL);
    if (!window)
    {
        std::println("glfwCreateWindow Fail");

        glfwTerminate();
        return -1;
    }

    SimpleTriangleApp simpleTriangleApp;
    simpleTriangleApp.initialize(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Vulkan rendering would go here */
        simpleTriangleApp.mainLoop();

        /* Poll for and process events */
        glfwPollEvents();
    }

    //simpleTriangleApp.cleanup();
    glfwTerminate();

    return 0;
}
