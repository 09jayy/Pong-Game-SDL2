cmake_minimum_required(VERSION 3.14)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create the executable for your project
add_executable(Pong-Game-SDL2 main.cpp)

# Find pre-installed SDL2 in CMAKE_PREFIX_PATH
find_package(SDL2 QUIET)
if(SDL2_FOUND)
    message(STATUS "Using SDL2 via find_package")

    add_custom_command(TARGET Pong-Game-SDL2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_LIBDIR}/SDL2.dll"
            $<TARGET_FILE_DIR:Pong-Game-SDL2>
        COMMENT "Copying SDL2.dll to target directory"
    )
endif()

if(NOT SDL2_FOUND)
    # Add SDL2 as an external project
    include(FetchContent)
    FetchContent_Declare(
      SDL2
      GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
      GIT_TAG release-2.30.6  # Use the latest stable tag or branch
    )

    # Build SDL2
    FetchContent_MakeAvailable(SDL2)

    # Custom command to copy the SDL2.dll or SDL2d.dll file after build
    add_custom_command(TARGET Pong-Game-SDL2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<$<CONFIG:Debug>:${CMAKE_BINARY_DIR}/_deps/sdl2-build/SDL2d.dll>
            $<$<CONFIG:Release>:${CMAKE_BINARY_DIR}/_deps/sdl2-build/SDL2.dll>
            $<TARGET_FILE_DIR:Pong-Game-SDL2>
        COMMENT "Copying SDL2.dll or SDL2d.dll to target directory based on build configuration"
    )
endif()

# Link your project with SDL2main first, then SDL2
target_link_libraries(Pong-Game-SDL2 PRIVATE SDL2::SDL2main SDL2::SDL2)