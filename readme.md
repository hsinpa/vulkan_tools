
## MacOS
brew install glfw molten-vk vulkan-loader pkg-config

## Windows
``` bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat

# Install GLFW
.\vcpkg install glfw3:x64-windows

```

Set this in CMake options field <br>
-DCMAKE_TOOLCHAIN_FILE=D:/CodeStation/C++/vcpkg/scripts/buildsystems/vcpkg.cmake
