add_library(game
  src/Game.cpp
  src/TileMap.cpp
  src/TileRegistry.cpp
  src/World.cpp)

target_include_directories(game
  PUBLIC include
  PUBLIC ${CMAKE_SOURCE_DIR}/core/include)

target_link_libraries(game
  PUBLIC engine)
