add_library(engine STATIC
  src/Engine.cpp
  src/Renderer.cpp
  src/EntityManager.cpp
  src/ComponentManager.cpp)

target_include_directories(engine
  PUBLIC include
  PUBLIC ${CMAKE_SOURCE_DIR}/core/include)

target_link_libraries(engine
  PRIVATE SDL3::SDL3
  PRIVATE imgui)
