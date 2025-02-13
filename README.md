# Pong-Game-SDL2

# Configure and Build with CMake

Prerequisites:

- Git
- CMake
- C++ compiler

First, clone the repository

```sh
git clone https://github.com/09jayy/Pong-Game-SDL2
cd Pong-Game-SDL2
```

Note: The CMakeLists.txt will first use `find_package()` to locate dependencies (SDL2, SDL_ttf) before attempting to download the respective repository from github

> If you are not using a package manager or run into errors in configuration try add cmake flag `-DSDL2TTF_VENDORED=ON` into `cmake` configure command

## Open in Visual Studio as CMake Project (Recommended)

1. In Visual Studio: File > Open > CMake.. > "Pong-Game-SDL2/CMakeLists.txt"
1. Select configuration (e.g. x64-Debug, x64-Release)
1. Run CMake Configuration (this will run using CMakePresets.json)
1. Build Project (Ctrl+Shift+B / Cmd+Shift+B)
1. Run Pong-Game-SDL.exe (Shift+F5)

## Build & Compile

### 1. Use CMake to Generate Build System

```sh
mkdir build    # 1. Create build directory
cd build       # 2. Change working directory to new build directory
cmake ..       # 3. Run CMake configuration
```

Optional Flags for CMake configuration include:

- `-G <build-system-name>` to build using spesific build system like ninja or msbuild
- `DCCMAKE_BUILD_TYPE=Debug | DCCMAKE_BUILD_TYPE=Release` to build for Debug or Release
- `-DSDL2TTF_VENDORED=ON` If not using a package manager or run into errors in config

### 2. Use Build System to Compile to executable file

From within the build directory, run your appropriate build command for your choosen build system. Examples include:

```sh
ninja                           # For Ninja build system
msbuild Pong-Game-SDL2.sln      # For Msbuild System
```

### 3. Run Executable

Locate the generated executable file and run, located in the src folder or Debug/Release folder within the src folder.

```sh
Pong-Game-SDL2.exe     # For Windows
./Pong-Game-SDL2.out   # For Mac
```
