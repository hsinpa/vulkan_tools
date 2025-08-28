#include "include/GLFW/glfw3.h"

int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Tell GLFW not to create an OpenGL context */
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    /* Create a windowed mode window without OpenGL context */
    window = glfwCreateWindow(640, 480, "Vulkan Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Vulkan rendering would go here */

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}