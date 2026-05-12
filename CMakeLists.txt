cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(discere_sim
  VERSION "0.1"
  DESCRIPTION "Demo of simple sim strategy game"
  LANGUAGES CXX)

### EXTERNAL LIBRARIES ###
find_package(SDL3 REQUIRED)

add_library(
  imgui
  third_party/imgui/imgui.cpp
  third_party/imgui/imgui_draw.cpp
  third_party/imgui/imgui_tables.cpp
  third_party/imgui/imgui_widgets.cpp
  third_party/imgui/imgui_demo.cpp

  third_party/imgui/backends/imgui_impl_sdl3.cpp
  third_party/imgui/backends/imgui_impl_sdlrenderer3.cpp
)

target_include_directories(
  imgui
  PUBLIC
    third_party/imgui
    third_party/imgui/backends
)

target_link_libraries(
  imgui
  PUBLIC SDL3::SDL3
)

### ENGINE ###
add_subdirectory(engine)

### GAME ###
add_subdirectory(game)

### ENTRY POINT ###
add_executable(${PROJECT_NAME}
  src/main.cpp)

target_link_libraries(${PROJECT_NAME}
  PRIVATE game)
