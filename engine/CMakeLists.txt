add_library(engine STATIC
  src/Engine.cpp
  src/Renderer.cpp)

target_include_directories(engine
  PUBLIC include)

target_link_libraries(engine
  PRIVATE SDL3::SDL3
  PRIVATE imgui)
