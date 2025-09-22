cmake_minimum_required(VERSION 3.5)
project(vulkan_tools)

set(CMAKE_CXX_STANDARD 23)


find_package(Vulkan REQUIRED)
find_package(PkgConfig REQUIRED)

# Create an imported target from pkg-config
pkg_check_modules(GLFW3 REQUIRED IMPORTED_TARGET glfw3)

add_executable(vulkan_tools main.cpp
        SimpleTriangleApp.cpp)

# Headers
target_include_directories(vulkan_tools PRIVATE
        ${Vulkan_INCLUDE_DIRS}
        ${GLFW3_INCLUDE_DIRS}        # -> /opt/homebrew/Cellar/glfw/3.4/include
)

# Very important: add the library search path so -lglfw is found
target_link_directories(vulkan_tools PRIVATE
        ${GLFW3_LIBRARY_DIRS}        # -> /opt/homebrew/Cellar/glfw/3.4/lib
)

# Link GLFW based on platform
if(WIN32)
    target_link_libraries(vulkan_tools
            ${Vulkan_LIBRARIES}
            ${GLFW3_LIBRARIES}
            vulkan-1  # Vulkan library on Windows
    )
elseif(APPLE)
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
