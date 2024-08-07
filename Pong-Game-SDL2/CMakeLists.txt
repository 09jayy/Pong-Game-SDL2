# CMakeList.txt : CMake project for Pong-Game-SDL2, include source and define
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

include_directories(${SDL2_INCLUDE_DIR})

# Add source to this project's executable.
add_executable (Pong-Game-SDL2 "main.cpp" "main.h")

target_link_libraries(Pong-Game-SDL2 SDL2 SDL2main)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pong-Game-SDL2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# Ensure the SDL2d.dll file exists
if (EXISTS "${CMAKE_BINARY_DIR}/_deps/sdl2-build/SDL2d.dll")
	message("SDL2d.dll has been found")
else(NOT EXISTS "${CMAKE_BINARY_DIR}/_deps/sdl2-build/SDL2d.dll")
	message(FATAL_ERROR "SDL2d.dll NOT BEEN FOUND")
endif()
# Custom command to copy the SDL2.dll file after build

add_custom_command(TARGET Pong-Game-SDL2 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_BINARY_DIR}/_deps/sdl2-build/SDL2d.dll"
  $<TARGET_FILE_DIR:Pong-Game-SDL2>
  COMMENT "Copying SDL2.dll to target directory"
)