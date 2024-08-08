# CMakeLists.txt : CMake project for Pong-Game-SDL2, include source and define
# project specific logic here.
#

include(FetchContent)

# Fetch SDL2
FetchContent_Declare(
	SDL2
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
	GIT_TAG	release-2.30.6
	GIT_PROGRESS TRUE
	GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(SDL2)

# Add source to this project's executable.
add_executable (Pong-Game-SDL2 "main.cpp" "main.h")

target_link_libraries(Pong-Game-SDL2 SDL2::SDL2 SDL2::SDL2main)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pong-Game-SDL2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# Custom command to copy the SDL2.dll or SDL2d.dll file after build
add_custom_command(TARGET Pong-Game-SDL2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<$<CONFIG:Debug>:${CMAKE_BINARY_DIR}/_deps/sdl2-build/SDL2d.dll>
        $<$<CONFIG:Release>:${CMAKE_BINARY_DIR}/_deps/sdl2-build/SDL2.dll>
        $<TARGET_FILE_DIR:Pong-Game-SDL2>
    COMMENT "Copying SDL2.dll or SDL2d.dll to target directory based on build configuration"
)