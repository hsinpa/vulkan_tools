cmake_minimum_required(VERSION 3.5)
project(vulkan_tools)

set(CMAKE_CXX_STANDARD 23)

find_package(Vulkan REQUIRED)

add_executable(vulkan_tools main.cpp)

# Link GLFW based on platform
if(WIN32)
    target_link_libraries(vulkan_tools
            ${CMAKE_CURRENT_SOURCE_DIR}/plugins/glfw/lib-mingw-w64/libglfw3dll.a
            vulkan-1  # Vulkan library on Windows
    )
elseif(APPLE)
    target_link_libraries(vulkan_tools
            ${CMAKE_CURRENT_SOURCE_DIR}/plugins/glfw/lib-universal/libglfw3.a
            ${Vulkan_LIBRARIES}
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreFoundation"
            "-framework CoreVideo"
            "-framework Metal"
            "-framework QuartzCore"
    )
endif()