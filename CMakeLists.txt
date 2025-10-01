cmake_minimum_required(VERSION 3.30)
project(vulkan_tools)

set(CMAKE_CXX_STANDARD 23)


find_package(Vulkan REQUIRED)

# Platform-specific GLFW setup
if(WIN32)
    # Option A: Use find_package if GLFW was installed via vcpkg
    find_package(glfw3 CONFIG REQUIRED)
elseif(APPLE)
    # macOS: Use pkg-config as before
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GLFW3 REQUIRED IMPORTED_TARGET glfw3)
    set(GLFW_LIBRARY PkgConfig::GLFW3)
endif()

add_executable(vulkan_tools main.cpp SimpleTriangleApp.cpp)

# Link GLFW based on platform
if(WIN32)
    target_link_libraries(vulkan_tools
            Vulkan::Vulkan
            glfw
    )
elseif(APPLE)
    # Headers
    target_include_directories(vulkan_tools PRIVATE
            ${Vulkan_INCLUDE_DIRS}
            ${GLFW3_INCLUDE_DIRS}        # -> /opt/homebrew/Cellar/glfw/3.4/include
    )

    # Very important: add the library search path so -lglfw is found
    target_link_directories(vulkan_tools PRIVATE
            ${GLFW3_LIBRARY_DIRS}        # -> /opt/homebrew/Cellar/glfw/3.4/lib
    )

    # Link libs
    target_link_libraries(vulkan_tools PRIVATE
            ${Vulkan_LIBRARIES}
            ${GLFW3_LIBRARIES}
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreFoundation"
            "-framework CoreVideo"
            "-framework QuartzCore"
            "-framework Metal"
    )
endif()

# Extra flags that pkg-config may provide (optional but harmless)
target_compile_options(vulkan_tools PRIVATE ${GLFW3_CFLAGS_OTHER})
target_link_options(vulkan_tools PRIVATE ${GLFW3_LDFLAGS_OTHER})
