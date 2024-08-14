cmake_minimum_required(VERSION 3.14)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all sources in directory
file(GLOB_RECURSE SOURCES "*.hpp" "*.cpp")

# Create the executable for your project
add_executable(Pong-Game-SDL2 ${SOURCES})

# Find pre-installed SDL2 in CMAKE_PREFIX_PATH
find_package(SDL2 QUIET)
if(SDL2_FOUND)
    message(STATUS "Using SDL2 via find_package")
endif()

if(NOT SDL2_FOUND)
    message(STATUS "Using SDL2 via Github.com")

    # Add SDL2 as an external project
    include(FetchContent)
    FetchContent_Declare(
      SDL2
      GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
      GIT_TAG release-2.30.6  # Use the latest stable tag or branch
    )

    # Build SDL2
    FetchContent_MakeAvailable(SDL2)
endif()

# Add header files to include directories
target_include_directories(Pong-Game-SDL2 PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Link your project with SDL2main first, then SDL2
target_link_libraries(Pong-Game-SDL2 PRIVATE SDL2::SDL2main SDL2::SDL2)

# Copy SDL2 DLLs to the output directory
add_custom_command(TARGET Pong-Game-SDL2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:Pong-Game-SDL2> $<TARGET_FILE_DIR:Pong-Game-SDL2>
    COMMAND_EXPAND_LISTS
)