# CMakeList.txt : CMake project for Pong-Game-SDL2, include source and define
# project specific logic here.
#

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add source to this project's executable.
add_executable (Pong-Game-SDL2 "main.cpp" "main.h")

target_link_libraries(Pong-Game-SDL2 ${SDL2_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pong-Game-SDL2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# Ensure the SDL2.dll file exists
if(NOT EXISTS "${SDL2_LIBDIR}/SDL2.dll")
  message(FATAL_ERROR "SDL2.dll not found in ${SDL2_LIBDIR}/SDL2.dll")
endif()

# Custom command to copy the SDL2.dll file after build
add_custom_command(TARGET Pong-Game-SDL2 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${SDL2_LIBDIR}/SDL2.dll"
  $<TARGET_FILE_DIR:Pong-Game-SDL2>
  COMMENT "Copying SDL2.dll to target directory"
)